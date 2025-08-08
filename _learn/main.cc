// main.cpp
extern "C" {
  #include <libavformat/avformat.h>
  #include <libavcodec/avcodec.h>
}
#include <iostream>
#include <fmt/core.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fmt::print("Usage: ./ffinfo <input>\n");
        return -1;
    }

    const char* filename = argv[1];
    avformat_network_init();

    AVFormatContext* fmt_ctx = nullptr;
    if (avformat_open_input(&fmt_ctx, filename, nullptr, nullptr) < 0) {
        fmt::print("Cannot open input file: {}\n", filename);
        return -1;
    }

    if (avformat_find_stream_info(fmt_ctx, nullptr) < 0) {
        fmt::print("Cannot find stream info\n");
        avformat_close_input(&fmt_ctx);
        return -1;
    }

    av_dump_format(fmt_ctx, 0, filename, 0);

    avformat_close_input(&fmt_ctx);
    return 0;
}
