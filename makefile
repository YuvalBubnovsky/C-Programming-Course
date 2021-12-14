.PHONY: clean all

all: test stringlib

test: main.o my_string.a stringLib.h
	gcc -Wall -g -o test main.c my_string.a

stringlib: my_string.a

my_string.a: stringLib.o
	ar -rcs my_string.a stringLib.o

stringLib.o: stringLib.c
	gcc -Wall -g -c stringLib.c

main.o: main.c stringLib.h
	gcc -Wall -g -c main.c

clean:
	rm -f *.o *.a *.so stringProg test