CFLAG = -std=c99
my_grep: Main.o search_str.o Colors.o
	gcc $(CFLAG) -o my_grep Main.o search_str.o Colors.o
Main.o: Main.c
	gcc $(CFLAG) -c Main.c
search_str.o:
	gcc $(CFLAG) -c search_str.c
Colors.o: Colors.c
	gcc $(CFLAG) -c Colors.c

.PHONY: all clean test

clean:
	-rm *.o my_grep

all: my_grep
