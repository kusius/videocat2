
#include "frame_process.h"
#include "videocat_utilities.h"
#include "argh.h"
#include <string>

void printUsage() {
    fprintf(stdout, "videocat2.exe -f [url/path]\n");
}

int main(int argc, char** argv) {
    //initPlatform();

    argh::parser cmdl(argc, argv, argh::parser::PREFER_PARAM_FOR_UNREG_OPTION);

    if (cmdl[{"-h", "--help"}]) {
        printUsage();
        return 0;
    }

    std::string url; 
    if (!(cmdl({ "-f", "--file_path"}) >> url )) {
        printUsage();
        return -1;
    }

    fprintf(stdout, "Url passed %s\n", url.c_str());

    FrameProcessor *frameProcesor = getFrameProcessor(url.c_str());
    if(!frameProcesor) {
        fprintf(stderr, "Could not open stream for url %s\n", url.c_str());
        return -1;
    }

    frameProcesor->onMetadataDecoded = [](std::unordered_map<KLVKey, KLVData> klvmap) {
        fprintf(stdout, "Tail number: %s\n", klvmap[KLVPlatformTailNumber].stringValue.c_str());
    };

    // thrd_join is the standard way, however we have a thrd_detach inside the
    // thread processing function. This results in a race condition because 
    // both thrd_detach and thrd_join try to unregister the thread from the OS.
    // It is a different model of use depending on the application (command line vs desktop / event based).
    // For now we leave the join out of the equation and allow the thread to detach by itself. 
    // Eventually we would want to support both models (ideas?)

    //thrd_join(frameProcesor->thread, 0);
    //fprintf(stdout, "Stream ended\n");
    

#if defined _DEBUG
    while(true);
#endif
    return 0;
}