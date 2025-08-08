## ffmpeg编译配置命令

```sh
./configure   --prefix=./build   --enable-debug=3   --disable-optimizations   --disable-stripping   --enable-extra-warnings   --disable-mmx --disable-inline-asm   --extra-cflags="-g -Og -fno-omit-frame-pointer -fno-inline"
```