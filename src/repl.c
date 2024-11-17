#include <stdio.h>
#include <string.h>
#include "btree.h"

void start_repl() {
    char command[256];
    int running = 1;

    while (running) {
        printf("Entrez une commande (insert/select/exit): ");
        fgets(command, sizeof(command), stdin);

        // Supprimer le saut de ligne
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "insert") == 0) {
            insert_data();
        } else if (strcmp(command, "select") == 0) {
            select_data();
        } else if (strcmp(command, "exit") == 0) {
            running = 0;
            printf("Au revoir !\n");
        } else {
            printf("Commande invalide.\n");
        }
    }
}
