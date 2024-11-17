#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // Nécessaire pour configurer l'encodage
#include "repl.h"  // Inclure repl.h

int main() {
    setlocale(LC_ALL, ""); // Configure l'encodage en UTF-8 pour tout le programme

    printf("Bienvenue dans la base de données simple !\n");

    // Lancement de la boucle REPL (Read-Eval-Print-Loop)
    start_repl();

    return 0;
}
