CC=gcc
CFLAGS=-Wall -g

all: isort txtfind
isort: isort.c
	$(CC) $(CFLAGS) -o isort isort.c

txtfind: txtfind.c
	$(CC) $(CFLAGS) -o txtfind txtfind.c

.PHONY: clean all

clean:
	rm -f isort txtfind