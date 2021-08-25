CC = gcc
CFLAGS = -Wall -std=c99 -g

all: aotat

aotat: aotat.o
	$(CC) $(CFLAGS) -o aotat aotat.o

aotat.o:
	$(CC) $(CLAGS) -c aotat.c

clean:
	rm -f aotat *.a *.o
