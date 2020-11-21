my_grep: Main.o search_str.o Colors.o
	gcc -o my_grep Main.o search_str.o Colors.o
Main.o: Main.c
	gcc -c Main.c
search_str.o:
	gcc -c search_str.c
Colors.o: Colors.c
	gcc -c Colors.c

.PHONY: all clean test

clean:
	-rm *.o my_grep

all: my_grep
