#!/bin/sh
g++ main.cpp -Ilib/Display -Ilib/Time -std=c++11 -lallegro -Wall -O2 -o teste
time ./teste

