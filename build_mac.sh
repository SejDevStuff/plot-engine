#!/bin/sh
cd bin
g++ -c ../*.cpp ../src/*.cpp -I../src -I/opt/homebrew/Cellar/sfml/2.5.1_2/include
g++ *.o -o Game -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system
cd ..