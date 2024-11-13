#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"

// Fonction pour créer un nouveau noeud
Node* create_node(Row data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

// Insertion dans l'arbre binaire
Node* insert(Node* root, Row data) {
    if (root == NULL) return create_node(data);
    if (data.id < root->data.id) root->left = insert(root->left, data);
    else if (data.id > root->data.id) root->right = insert(root->right, data);
    return root;
}

// Recherche d'un noeud dans l'arbre
Node* search(Node* root, int id) {
    if (root == NULL || root->data.id == id) return root;
    if (id < root->data.id) return search(root->left, id);
    return search(root->right, id);
}

// Suppression d'un noeud
Node* delete(Node* root, int id) {
    if (root == NULL) return root;
    if (id < root->data.id) root->left = delete(root->left, id);
    else if (id > root->data.id) root->right = delete(root->right, id);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
    }
    return root;
}

// Affichage en ordre croissant
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("ID: %d, Name: %s\n", root->data.id, root->data.name);
        inorder(root->right);
    }
}

// Sauvegarde de l'arbre sur disque
void save_tree(Node* root, FILE *file) {
    if (root != NULL) {
        fwrite(&(root->data), sizeof(Row), 1, file);
        save_tree(root->left, file);
        save_tree(root->right, file);
    }
}

// Chargement de l'arbre depuis le disque
Node* load_tree(FILE *file) {
    Row data;
    Node* root = NULL;
    while (fread(&data, sizeof(Row), 1, file)) {
        root = insert(root, data);
    }
    return root;
}
