CFLAG = -std=c99
ex3_lb: ex3_lb.o port_share.o
	gcc $(CFLAG) -o ex3_lb ex3_lb.o port_share.o
ex3_lb.o: ex3_lb.c
	gcc $(CFLAG) -c ex3_lb.c
port_share.o: port_share.c
	gcc $(CFLAG) -c port_share.c

.PHONY: all clean test

clean:
	-rm *.o ex3_lb

all: ex3_lb