#!/bin/bash 

c++ ./main.cpp ./bat.cpp ./ball.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
./main
