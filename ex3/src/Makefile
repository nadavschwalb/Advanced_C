IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR) -std=c99

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = port_share.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = ex3_lb.o port_share.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ex3_lb: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
