CFLAG = -std=c99
my_grep: Main.o search_str.o Print_Formats.o Regex_Engine.o
	gcc $(CFLAG) -o my_grep Main.o search_str.o Print_Formats.o Regex_Engine.o
Main.o: Main.c
	gcc $(CFLAG) -c Main.c
search_str.o: search_str.c
	gcc $(CFLAG) -c search_str.c
Print_Formats.o: Print_Formats.c
	gcc $(CFLAG) -c Print_Formats.c
Regex_Engine.o: Regex_Engine.c
	gcc $(CFLAG) -c Regex_Engine.c

.PHONY: all clean test

clean:
	-rm *.o my_grep

all: my_grep
