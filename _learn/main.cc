// main.cpp
extern "C" {
  #include <libavformat/avformat.h>
  #include <libavcodec/avcodec.h>
}
#include <iostream>
#include <fmt/core.h>
#include <CLI/CLI.hpp>
#include <string>

int main(int argc, char* argv[]) {
    std::string video_name;
    CLI::App app("ffmpeg demo");
    app.add_option("video", video_name, "Video Name")->required();
    CLI11_PARSE(app, argc, argv);

    avformat_network_init();

    AVFormatContext* fmt_ctx = nullptr;
    if (avformat_open_input(&fmt_ctx, video_name.c_str(), nullptr, nullptr) < 0) {
        fmt::print("Cannot open input file: {}\n", video_name);
        return -1;
    }

    if (avformat_find_stream_info(fmt_ctx, nullptr) < 0) {
        fmt::print("Cannot find stream info\n");
        avformat_close_input(&fmt_ctx);
        return -1;
    }

    
    fmt::print("--------------------------------------------------------\n");
    fmt::print("format: {}, dur: {}\n", fmt_ctx->iformat->long_name, fmt_ctx->duration);
    
    fmt::print("--------------------------------------------------------\n");

    av_dump_format(fmt_ctx, 0, video_name.c_str(), 0);

    avformat_close_input(&fmt_ctx);
    return 0;
}
