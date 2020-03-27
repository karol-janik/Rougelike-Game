CC = gcc
CFLAGS = -lncurses -I$(IDIR)

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c

all: rouge run clean

rouge:
	$(CC) $(SOURCES) $(CFLAGS) -o $@
run:
	./rouge

clean:
	rm rouge