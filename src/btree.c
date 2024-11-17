#include "btree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *root = NULL;

Node* create_node(char *data) { // fonction pour creer un nouveau noeud
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->data, data);
    new_node->left = new_node->right = NULL;
    return new_node;
}

void insert_data() { // fonction pour inserer une donnee dans larbre
    char data[256];
    printf("Entrez la donnee a inserer : ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = 0; // supprimer le saut de ligne

    Node *new_node = create_node(data);

    if (root == NULL) {  // insertion dans l'arbre binaire
        root = new_node;
    } else {
        Node *current = root;
        while (1) {
            if (strcmp(data, current->data) < 0) {
                if (current->left == NULL) { // aller a gauche
                    current->left = new_node;
                    break;
                }
                current = current->left;
            } else {
                if (current->right == NULL) { // aller a gauche
                    current->right = new_node;
                    break;
                }
                current = current->right;
            }
        }
    }
    printf("Donnee inseree avec succes !\n");
}

void select_data() { // fonction pour afficher les donnees 
    if (root == NULL) {
        printf("Aucune donnee a afficher.\n");
        return;
    }

    printf("Donnees dans l'arbre :\n");
    inorder_traversal(root);
}

void inorder_traversal(Node *node) { // fonction pour traverser larbre en ordre et afficher les donnees
    if (node != NULL) {
        inorder_traversal(node->left);
        printf("%s\n", node->data);
        inorder_traversal(node->right);
    }
}
