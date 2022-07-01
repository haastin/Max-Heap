EXEC = run
CC = gcc
CFLAGS = -c -Wall

$(EXEC): main.o util.o heap.o
	$(CC) -o $(EXEC) main.o util.o heap.o -lm

main.o: main.c util.c heap.c
	$(CC) $(CFLAGS) main.c util.c heap.c -lm

util.o: util.h util.c 
	$(CC) $(CFLAGS) util.c -lm

heap.o: heap.h heap.c 
	$(CC) $(CFLAGS) heap.c -lm

clean:
	rm *.o