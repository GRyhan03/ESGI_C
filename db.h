#ifndef DB_H
#define DB_H

typedef struct Row {
    int id;
    char name[50];
} Row;

typedef struct Node {
    Row data;
    struct Node *left;
    struct Node *right;
} Node;

// Fonction de gestion d'arbre binaire
Node* insert(Node* root, Row data);
Node* search(Node* root, int id);
Node* delete(Node* root, int id);
void inorder(Node* root);
void save_tree(Node *root, FILE *file);
Node* load_tree(FILE *file);

#endif
