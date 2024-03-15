bin:
	mkdir bin

bin/pan.c: bin main.pml
	spin -a main.pml
	mv pan* bin

bin/pan: bin/pan.c
	gcc bin/pan.c -o bin/pan

dot: bin/pan
	bin/pan -D
