.PHONY: clean all

all: graph myGraph

graph: main.o my_graph.a graph.h
	gcc -Wall -ggdb3 -g -o graph main.c my_graph.a

myGraph: my_graph.a

my_graph.a: graph_lib.o
	ar -rcs my_graph.a graph.o

graph_lib.o: graph.c
	gcc -Wall -g -c graph.c

main.o: main.c graph.h
	gcc -Wall -g -c main.c

clean:
	rm -f *.o *.a *.so graph myGraph