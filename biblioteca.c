#include "biblioteca.h"

// Função para criar um novo nó
Node* createNode(int id, char* title, char* author) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
    newNode->id = id;
    strcpy(newNode->title, title);
    strcpy(newNode->author, author);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um nó na BST
Node* insert(Node* root, int id, char* title, char* author) {
    // Se a árvore estiver vazia, criar o nó raiz
    if (root == NULL) {
        return createNode(id, title, author);
    }

    // Se o ID já existe, não inserir
    if (id == root->id) {
        printf("ID %d já existe! Livro não inserido.\n", id);
        return root;
    }

    // Inserir na subárvore esquerda se ID menor
    if (id < root->id) {
        root->left = insert(root->left, id, title, author);
    }
    // Inserir na subárvore direita se ID maior
    else if (id > root->id) {
        root->right = insert(root->right, id, title, author);
    }

    return root;
}

// Função para buscar um nó na BST
Node* search(Node* root, int id) {
    // Caso base: árvore vazia ou ID encontrado
    if (root == NULL || root->id == id) {
        return root;
    }

    // Se ID é menor, buscar na subárvore esquerda
    if (id < root->id) {
        return search(root->left, id);
    }
    // Se ID é maior, buscar na subárvore direita
    else {
        return search(root->right, id);
    }
}

// Função para encontrar o nó com menor valor (mais à esquerda)
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Função para remover um nó da BST
Node* deleteNode(Node* root, int id) {
    // Caso base: árvore vazia
    if (root == NULL) {
        return root;
    }

    // Navegar até encontrar o nó
    if (id < root->id) {
        root->left = deleteNode(root->left, id);
    }
    else if (id > root->id) {
        root->right = deleteNode(root->right, id);
    }
    else {
        // Nó encontrado - três casos de remoção

        // Caso 1: Nó sem filhos (folha)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Caso 2: Nó com apenas um filho
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Caso 3: Nó com dois filhos
        else {
            // Encontrar o sucessor in-ordem (menor valor na subárvore direita)
            Node* temp = findMin(root->right);

            // Copiar os dados do sucessor para este nó
            root->id = temp->id;
            strcpy(root->title, temp->title);
            strcpy(root->author, temp->author);

            // Remover o sucessor
            root->right = deleteNode(root->right, temp->id);
        }
    }
    return root;
}

// Função para listar todos os livros em ordem crescente (in-ordem)
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("  ID: %d | Título: %s | Autor: %s\n",
               root->id, root->title, root->author);
        inorderTraversal(root->right);
    }
}

// Função para contar o número de livros
int countBooks(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countBooks(root->left) + countBooks(root->right);
}

// Função para calcular a altura da árvore
int treeHeight(Node* root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Função para exibir o menu
void displayMenu() {
    printf("\n========== SISTEMA DE BIBLIOTECA UEPA ==========\n");
    printf("1. Inserir livro\n");
    printf("2. Buscar livro por ID\n");
    printf("3. Remover livro\n");
    printf("4. Listar todos os livros\n");
    printf("5. Estatísticas da biblioteca\n");
    printf("6. Inserir livros de exemplo\n");
    printf("0. Sair\n");
    printf("=============================================\n");
    printf("Escolha uma opção: ");
}

// Função para limpar o buffer de entrada
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

