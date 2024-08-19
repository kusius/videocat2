#pragma once

extern "C" {
#include <libavformat/avformat.h>
#include <libavutil/avutil.h>
#include <libavutil/dict.h>
#include <libavutil/opt.h>
#include <libavcodec/avcodec.h>
#include <tinycthread.h>
}

#include "videocat_utilities.h"
#include <klvp/klvprsr.h>
#include <klvp/decode.h>
#include <unordered_map>
#include <functional>
typedef std::function<void(std::unordered_map<KLVKey, KLVData>)> OnMetadataDecodedCallback;


class MyKlvParser : public lcss::KLVParser {
public:
	bool isDone = false;
	std::unordered_map<KLVKey, KLVData> klvmap;

	void onBeginSet(int len, lcss::TYPE type) override {
		isDone = false;
		klvmap.clear();
		lcss::KLVParser::onBeginSet(len, type);
	}

	void onElement(lcss::KLVElement& klv) override {
		lcss::KLVDecodeVisitor decoder;
		klv.Accept(decoder);

		KLVData klvData = {
			.key = getKeyFromInt(klv.key()),
			.keyString = getKeyAsString(klv.key()),
			.intValue = decoder.nValue,
			.doubleValue = decoder.fValue,
			.stringValue = decoder.strValue,
			.timeValue = decoder.tmValue
		};

		klvmap[klvData.key] = klvData;
		lcss::KLVParser::onElement(klv);
	}

	void onEndSet() override {
		isDone = true;
	}

private:


};

struct FrameProcessor {
	int id;
	MyKlvParser* klvParser{ nullptr };
	OnMetadataDecodedCallback onMetadataDecoded{ nullptr };
	//IFrameProcessCallback *callback;
	AVFormatContext* formatContext;
	//AVFrame* frame;
	//AVPacket* packet;
	int dataStreamIndex;
	bool isDone = true;
	char url[512] = { 0 };
	thrd_t thread;
};

FrameProcessor* getFrameProcessor(const char *url);