CC = gcc
CFLAGS = -lncurses -I$(IDIR)

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c

all: rouge  

rouge: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o $@
run:
	./rouge

clean:
	rm rouge