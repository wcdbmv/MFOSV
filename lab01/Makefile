bin:
	mkdir bin

bin/pan.c: bin main.pml
	spin -a main.pml
	mv pan* bin

bin/pan: bin/pan.c
	gcc bin/pan.c -o bin/pan

dot: bin/pan
	bin/pan -D

bin/main: bin main.cpp
	clang++ -std=c++20 main.cpp -o bin/main

run: bin/main
	bin/main
