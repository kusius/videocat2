#include "frame_process.h"
#include <stdio.h>
#include <videocat_utilities.h>
#include <vector>


static bool isInitialized = false;
static int frameProcessorId = 0;
const int MAX_PROCESSORS = 50;
static FrameProcessor frameProcessors[MAX_PROCESSORS] = {0};

static void printAVError(const int error, const char *customMessage) {
	char errorMessage[50];
	av_strerror(error, errorMessage, sizeof(errorMessage));
	fprintf(stderr, "%s %s\n", customMessage, errorMessage);
}

static const char *findMetadata(AVFormatContext *context, const char* name) {
	const AVDictionaryEntry* tag = NULL;
	int metadataSize = av_dict_count(context->metadata);
	
	while ((tag = av_dict_iterate(context->metadata, tag)))
		printf("%s=%s\n", tag->key, tag->value);

	while ((tag = av_dict_get(context->metadata, name, tag, AV_DICT_IGNORE_SUFFIX))) {
		fprintf(stdout, "\t %s : %s\n", tag->key, tag->value);
	}

	return "";
}

// processing function that get launched in background thread
static int processFrames(void* arg) {
	FrameProcessor* localFrameProcessor = (FrameProcessor*)arg;
	
	localFrameProcessor->klvParser = new MyKlvParser();
	localFrameProcessor->isDone = false;
	
	int result = -1;
	AVPacket *packet = av_packet_alloc();

	if (!packet) {
		printAVError(AVERROR(ENOMEM), "Could not allocate packet: ");
		goto done;
	}


	while (!localFrameProcessor->isDone && av_read_frame(localFrameProcessor->formatContext, packet) >= 0) {
		if (packet->stream_index == localFrameProcessor->dataStreamIndex) {

			localFrameProcessor->klvParser->parse({ packet->data, gsl::narrow_cast<std::size_t>(packet->size) });

			if (localFrameProcessor->klvParser->isDone && localFrameProcessor->onMetadataDecoded != nullptr) {
				localFrameProcessor->onMetadataDecoded(localFrameProcessor->klvParser->klvmap);
			}
		}

		av_packet_unref(packet);
	}

done:
	localFrameProcessor->isDone = true;
	//clean up memory
	delete localFrameProcessor->klvParser;
	avformat_close_input(&localFrameProcessor->formatContext);
	av_packet_free(&packet);
	
	thrd_t threadId = localFrameProcessor->thread;
	thrd_detach(threadId);

	localFrameProcessor = { 0 };
	thrd_exit(0);
	return 0;
}

static int findAvailableProcessorIndex() {
	int i;
	for (i = 0; i < MAX_PROCESSORS; i++) {
		if (frameProcessors[i].isDone) break;
	};
	return i;
}

FrameProcessor* getFrameProcessor(const char *url) {
	int result;
	result = findAvailableProcessorIndex(); 
	if (result >= MAX_PROCESSORS) return 0;


	FrameProcessor* frameProcessor = &frameProcessors[result];
	*frameProcessor = { 0 };

	strcpy_s(frameProcessor->url, 512, url);

	if (!isInitialized) {
		avformat_network_init();
		isInitialized = true;
	}
	

	result = avformat_open_input(&frameProcessor->formatContext, url, 0, 0);

	if (result) {
		printAVError(result, "Could not open input:");
		return 0;
	}

	result = avformat_find_stream_info(frameProcessor->formatContext, NULL);
	if (result) {
		printAVError(result, "Could not find stream info: ");
		return 0;
	}

	av_dump_format(frameProcessor->formatContext, 0, url, 0);
	findMetadata(frameProcessor->formatContext, "");


	result = av_find_best_stream(frameProcessor->formatContext, AVMEDIA_TYPE_DATA, -1, -1, 0, 0);
	if (result < 0) {
		printAVError(AVERROR(ENOENT), "Could not find data stream: \n");
		return 0;
	}
	else {
		fprintf(stdout, "Found data stream at index %d\n", result);
		frameProcessor->dataStreamIndex = result;
	}


	// start receiving and parsing frames
	result = thrd_create(&frameProcessor->thread, processFrames, frameProcessor);
	if (result != thrd_success) {
		DEBUG_PRINT("Could not start decode thread: %d", result);
		return 0;
	}


	return frameProcessor;
}