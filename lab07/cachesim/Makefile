all: cachesim

cachesim: cachesim.o cachelab-tools.o
	gcc -g -Wall cachesim.o cachelab-tools.o -o cachesim -lm 

cachesim.o: cachesim.c
	gcc -g -Wall -c cachesim.c

cachelab-tools.o: cachelab-tools.c  cachelab-tools.h
	gcc -g -Wall -c cachelab-tools.c 

clean:
	rm -rf *.o
	rm cachesim
