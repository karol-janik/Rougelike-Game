CC = gcc
CFLAGS = -lncurses

SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c

all: rouge

rouge:
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run:
	./rouge