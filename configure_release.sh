#! /bin/sh
rm -rf out/build
cmake -DWITH_MY_TESTS=OFF -S . -B out/build