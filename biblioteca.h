#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estrutura do nó da árvore binária
typedef struct Node {
    int id;
    char title[100];
    char author[100];
    struct Node* left;
    struct Node* right;
} Node;

// Protótipos das funções
Node* createNode(int id, char* title, char* author);
Node* insert(Node* root, int id, char* title, char* author);
Node* search(Node* root, int id);
Node* findMin(Node* root);
Node* deleteNode(Node* root, int id);
void inorderTraversal(Node* root);
int countBooks(Node* root);
int treeHeight(Node* root);
void displayMenu();
void clearInputBuffer();

#endif //BIBLIOTECA_H

