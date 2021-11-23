#! /bin/bash

g++ -c speaker.cpp
g++ -c woofer.cpp
g++ -c tweeter.cpp
g++ -c speaker_main.cpp
g++ -o speaker speaker_main.o speaker.o woofer.o tweeter.o

