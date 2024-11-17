#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //encodage
#include "repl.h"  // inclure repl.h

int main() {
    setlocale(LC_ALL, ""); // configure l'encodage en UTF-8 pour tout le programme

    printf("Bienvenue dans la base de donnees simple !\n");

    start_repl(); // lancement de la boucle REPL

    return 0;
}
