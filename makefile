
.PHONY: clean all

all: connections

connections: main.o my_matlib.a my_mat.h
	gcc -Wall -g -o connections main.o my_matlib.a

matrixlib: my_matlib.a
my_matlib.a: my_mat.o
	ar -rcs my_matlib.a my_mat.o

my_mat.o: my_mat.c
	gcc -Wall -g -c my_mat.c

main.o: main.c my_mat.h
	gcc -Wall -g -c main.c


clean:
	rm -f *.o *.a *.so connections
