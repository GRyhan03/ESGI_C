CC = gcc
CFLAGS = -Wall -g

# Fichiers objets
OBJ = main.o repl.o btree.o

# Cible finale
all: main

# Compilation des fichiers objets
main: $(OBJ)
	$(CC) $(OBJ) -o main

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

repl.o: repl.c
	$(CC) $(CFLAGS) -c repl.c

btree.o: btree.c
	$(CC) $(CFLAGS) -c btree.c

# Nettoyage des fichiers objets
clean:
	rm -f *.o main

