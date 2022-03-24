PROGRAM=bounce
CC=g++
LD=g++
CFLAGS=-I. -c
LDFLAGS=-lncurses

all:  $(PROGRAM)

$(PROGRAM): Main.o Board.o
	$(LD) -o $@  Main.o Board.o $(LDFLAGS)

Main.o:  Main.cc Board.h
	$(CC) $(CFLAGS) $<

Board.o:  Board.cc Board.h
	$(CC) $(CFLAGS) $<

clean:
	rm -rf *.o $(PROGRAM)
