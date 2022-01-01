.PHONY: clean all

all: graph myGraph myPrio

graph: main.o my_graph.a graph.h my_prio.a priorityQueue.h
	gcc -Wall -ggdb3 -g -o graph main.c my_graph.a my_prio.a

myGraph: my_graph.a

myPrio: my_prio.a

my_graph.a: graph_lib.o
	ar -rcs my_graph.a graph.o

my_prio.a: prio_lib.o
	ar -rcs my_prio.a priorityQueue.o

graph_lib.o: graph.c
	gcc -Wall -g -c graph.c

prio_lib.o: priorityQueue.c
	gcc -Wall -g -c priorityQueue.c

main.o: main.c graph.h
	gcc -Wall -g -c main.c

clean:
	rm -f *.o *.a *.so graph myGraph