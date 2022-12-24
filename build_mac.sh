#!/bin/sh
echo -n "\n\n\n\n\n\n------------------------ COMPILE ------------------------"
cd bin
g++ -c ../test/*.cpp ../src/*.cpp -I../src -I/opt/homebrew/Cellar/sfml/2.5.1_2/include -std=c++11
g++ *.o -o Game -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system -D SFML_STATIC
cd ..