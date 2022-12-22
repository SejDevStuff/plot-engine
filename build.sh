#!/bin/sh
cd bin
g++ -c ../main.cpp ../src/*.cpp -I../src
g++ *.o -o Game -lsfml-graphics -lsfml-window -lsfml-system
cd ..