#ifndef BTREE_H
#define BTREE_H

// Déclaration des structures et fonctions
typedef struct Node {
    char data[256];
    struct Node *left, *right;
} Node;

Node* create_node(char *data);
void insert_data(void);
void select_data(void);
void inorder_traversal(Node *node);

#endif
