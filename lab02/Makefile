bin/with_mutex:
	mkdir -p bin/with_mutex

bin/with_mutex/pan.c: bin/with_mutex main.pml
	spin -a -o3 -DUSE_MUTEX main.pml
	mv pan* bin/with_mutex

bin/with_mutex/pan: bin/with_mutex/pan.c
	gcc bin/with_mutex/pan.c -o bin/with_mutex/pan

dot_with_mutex: bin/with_mutex/pan
	bin/with_mutex/pan -D

run_with_mutex:
	spin -DUSE_MUTEX main.pml


bin/without_mutex:
	mkdir -p bin/without_mutex

bin/without_mutex/pan.c: bin/without_mutex main.pml
	spin -a -o3 main.pml
	mv pan* bin/without_mutex

bin/without_mutex/pan: bin/without_mutex/pan.c
	gcc bin/without_mutex/pan.c -o bin/without_mutex/pan

dot_without_mutex: bin/without_mutex/pan
	bin/without_mutex/pan -D

run_without_mutex:
	spin main.pml
