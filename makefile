
.PHONY: clean all

all: connections

connections: main.o
	gcc -Wall -g -o connections main.o my_mat.c

main.o: main.c my_mat.h
	gcc -Wall -g -c main.c


clean:
	rm -f *.o *.a *.so connections
