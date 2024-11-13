#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"

int main() {
    Node* root = NULL;
    FILE *file;

    // Charger les données de l'arbre depuis un fichier
    file = fopen("db.bin", "rb");
    if (file != NULL) {
        root = load_tree(file);
        fclose(file);
    }

    int choice, id;
    char name[50];
    Row row;

    while (1) {
        printf("Options: 1. Insert 2. Select 3. Delete 4. Display 5. Save & Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert
                printf("Enter ID and Name: ");
                scanf("%d %49s", &id, name);
                row.id = id;
                strncpy(row.name, name, 50);
                root = insert(root, row);
                break;
            case 2: // Select
                printf("Enter ID to find: ");
                scanf("%d", &id);
                Node* found = search(root, id);
                if (found != NULL) printf("Found ID: %d, Name: %s\n", found->data.id, found->data.name);
                else printf("Row not found.\n");
                break;
            case 3: // Delete
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                root = delete(root, id);
                break;
            case 4: // Display all
                inorder(root);
                break;
            case 5: // Save and Exit
                file = fopen("db.bin", "wb");
                if (file != NULL) {
                    save_tree(root, file);
                    fclose(file);
                }
                exit(0);
        }
    }
    return 0;
}
