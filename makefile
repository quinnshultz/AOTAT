CC = gcc
CFLAGS = -Wall -std=c99 -g

all: aotat

aotat: aotat.o location.o misc.o object.o
	$(CC) $(CFLAGS) -o aotat aotat.o location.o misc.o object.o

aotat.o: aotat.c location.c location.h object.c object.h misc.c misc.h
	$(CC) $(CLAGS) -c aotat.c

location.o: location.c
	$(CC) $(CFLAGS) -c location.c

misc.o: misc.c
	$(CC) $(CFLAGS) -c misc.c

object.o: object.c
	$(CC) $(CFLAGS) -c object.c

clean:
	rm -f aotat *.a *.o
