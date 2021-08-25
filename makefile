CC = gcc
CFLAGS = -Wall -std=c99 -g

all: aotat

aotat: aotat.o aotatLib.a
	$(CC) $(CFLAGS) -o aotat aotat.o -L. aotatLib.a

aotatLib.a: location.o
	ar rcs aotatLib.a location.o

aotat.o: aotat.c aotat.h location.c
	$(CC) $(CLAGS) -c aotat.c

location.o: location.c
	$(CC) $(CFLAGS) -c location.c

clean:
	rm -f aotat *.a *.o
