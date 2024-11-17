#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[256];
    struct Node *left, *right;
} Node;

Node *root = NULL;

// Fonction pour créer un nouveau noeud
Node* create_node(char *data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->data, data);
    new_node->left = new_node->right = NULL;
    return new_node;
}

// Fonction pour insérer une donnée dans l'arbre
void insert_data() {
    char data[256];
    printf("Entrez la donnée à insérer : ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = 0; // Supprimer le saut de ligne

    Node *new_node = create_node(data);

    // Insertion dans l'arbre binaire
    if (root == NULL) {
        root = new_node;
    } else {
        Node *current = root;
        while (1) {
            if (strcmp(data, current->data) < 0) {
                // Aller à gauche
                if (current->left == NULL) {
                    current->left = new_node;
                    break;
                }
                current = current->left;
            } else {
                // Aller à droite
                if (current->right == NULL) {
                    current->right = new_node;
                    break;
                }
                current = current->right;
            }
        }
    }
    printf("Donnée insérée avec succès !\n");
}

// Fonction pour afficher les données (traversée en ordre)
void select_data() {
    if (root == NULL) {
        printf("Aucune donnée à afficher.\n");
        return;
    }

    printf("Données dans l'arbre :\n");
    inorder_traversal(root);
}

// Fonction pour traverser l'arbre en ordre et afficher les données
void inorder_traversal(Node *node) {
    if (node != NULL) {
        inorder_traversal(node->left);
        printf("%s\n", node->data);
        inorder_traversal(node->right);
    }
}
