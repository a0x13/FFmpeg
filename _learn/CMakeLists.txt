cmake_minimum_required(VERSION 3.12)
project(ffinfo_example C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

# 指定你自己编译 FFmpeg 时的安装目录
set(FFMPEG_ROOT "${CMAKE_SOURCE_DIR}/../build")

if (NOT CLI11_DIR)
    set(CLI11_DIR "~/Include/CLI11")
endif()
set(CLI11_INCLUDE_DIR "${CLI11_DIR}/include/")
message("-- CLI11 include dir: ${CLI11_INCLUDE_DIR}")
include_directories("${CLI11_INCLUDE_DIR}")

include_directories("${FFMPEG_ROOT}/include")

link_directories("${FFMPEG_ROOT}/lib")

add_executable(ffinfo main.cc)

# 链接 FFmpeg 库
target_link_libraries(ffinfo
    avformat avcodec avutil avdevice avfilter swscale swresample z lzma fmt
)
