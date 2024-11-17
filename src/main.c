#include <stdio.h>
#include <stdlib.h>
#include "repl.c"
#include <stdbool.h>
#include <string.h>


int main() {
    printf("Bienvenue dans la base de données simple !\n");

    // Lancement de la boucle REPL (Read-Eval-Print-Loop)
    start_repl();

    return 0;
}
