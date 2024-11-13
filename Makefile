CC = gcc
CFLAGS = -Wall -g
TARGET = main

all: $(TARGET)

$(TARGET): main.o db.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o db.o

main.o: main.c db.h
	$(CC) $(CFLAGS) -c main.c

db.o: db.c db.h
	$(CC) $(CFLAGS) -c db.c

clean:
	rm -f *.o $(TARGET)
