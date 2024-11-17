CC=gcc
CFLAGS=-Wall -g

# Fichiers objets
OBJ=main.o repl.o btree.o

# Cible par défaut
all: mon_programme

# Construction de l'exécutable
mon_programme: $(OBJ)
	$(CC) $(CFLAGS) -o mon_programme $(OBJ)

# Compilation de main.o
main.o: main.c repl.h btree.h
	$(CC) $(CFLAGS) -c main.c

# Compilation de repl.o
repl.o: repl.c repl.h
	$(CC) $(CFLAGS) -c repl.c

# Compilation de btree.o
btree.o: btree.c btree.h
	$(CC) $(CFLAGS) -c btree.c

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f *.o mon_programme
