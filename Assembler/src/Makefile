IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = parser.h code.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = assembler.o parser.o code.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: $(OBJ)

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

assembler: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
