#!/bin/sh
g++ main.cpp -Ilib/Display -Ilib/Time -Ilib/Color -std=c++11 -lallegro -Wall -O2 -o teste
time ./teste

