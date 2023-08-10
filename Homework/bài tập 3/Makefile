CC = gcc
CFLAGS = -Wall 

all: main

main: main.o date.o
	$(CC) $(CFLAGS) -o main main.o date.o

main.o: main.c date.h
	$(CC) $(CFLAGS) -c main.c

date.o: date.c date.h
	$(CC) $(CFLAGS) -c date.c

clean:
	rm -f main *.o
