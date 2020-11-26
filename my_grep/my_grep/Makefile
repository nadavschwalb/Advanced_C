CFLAG = -std=c99
my_grep: Main.o search_str.o Print_Formats.o
	gcc $(CFLAG) -o my_grep Main.o search_str.o Print_Formats.o
Main.o: Main.c
	gcc $(CFLAG) -c Main.c
search_str.o: search_str.c
	gcc $(CFLAG) -c search_str.c
Print_Formats.o: Print_Formats.c
	gcc $(CFLAG) -c Print_Formats.c

.PHONY: all clean test

clean:
	-rm *.o my_grep

all: my_grep
