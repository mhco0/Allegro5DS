#!/bin/sh
g++ main.cpp -Ilib/Display -Ilib/Time -Ilib/Color -Ilib/Image -Ilib/Timer -std=c++11 -lallegro -lallegro_image -Wall -O2 -o teste
time ./teste

