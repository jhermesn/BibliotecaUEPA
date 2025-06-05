#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "biblioteca.h"

// Função principal
int main() {
    setlocale(LC_ALL, "");

    Node* root = nullptr;
    int choice, id;
    char title[100], author[100];

    printf("=== SISTEMA DE GERENCIAMENTO DE BIBLIOTECA ===\n");
    printf("        Universidade do Estado do Pará\n");
    printf("          Estruturas de Dados - BST\n");

    do {
        displayMenu();
        scanf("%d", &choice);
        clearInputBuffer();

        switch(choice) {
            case 1: // Inserir livro
                printf("\n--- INSERIR NOVO LIVRO ---\n");
                printf("Digite o ID do livro: ");
                scanf("%d", &id);
                clearInputBuffer();

                printf("Digite o título do livro: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0';

                printf("Digite o autor do livro: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = '\0';

                root = insert(root, id, title, author);
                printf("\nLivro inserido com sucesso!\n");
                break;

            case 2: // Buscar livro
                printf("\n--- BUSCAR LIVRO ---\n");
                printf("Digite o ID do livro a buscar: ");
                scanf("%d", &id);
                clearInputBuffer();

                Node* found = search(root, id);
                if (found != NULL) {
                    printf("\nLivro encontrado:\n");
                    printf("  ID: %d\n", found->id);
                    printf("  Título: %s\n", found->title);
                    printf("  Autor: %s\n", found->author);
                } else {
                    printf("\nLivro com ID %d não encontrado.\n", id);
                }
                break;

            case 3: // Remover livro
                printf("\n--- REMOVER LIVRO ---\n");
                printf("Digite o ID do livro a remover: ");
                scanf("%d", &id);
                clearInputBuffer();

                Node* toRemove = search(root, id);
                if (toRemove != NULL) {
                    root = deleteNode(root, id);
                    printf("\nLivro com ID %d removido com sucesso!\n", id);
                } else {
                    printf("\nLivro com ID %d não encontrado.\n", id);
                }
                break;

            case 4: // Listar todos os livros
                printf("\n--- LISTAGEM DE LIVROS (Ordem Crescente por ID) ---\n");
                if (root == NULL) {
                    printf("A biblioteca está vazia.\n");
                } else {
                    inorderTraversal(root);
                }
                break;

            case 5: // Estatísticas
                printf("\n--- ESTATÍSTICAS DA BIBLIOTECA ---\n");
                printf("Total de livros: %d\n", countBooks(root));
                printf("Altura da árvore: %d\n", treeHeight(root));
                break;

            case 6: // Inserir livros de exemplo
                printf("\n--- INSERINDO LIVROS DE EXEMPLO ---\n");
                root = insert(root, 101, "Estruturas de Dados", "Mark Allen Weiss");
                root = insert(root, 202, "Algoritmos", "Robert Sedgewick");
                root = insert(root, 303, "Redes de Computadores", "Andrew S. Tanenbaum");
                root = insert(root, 150, "Banco de Dados", "Christopher J. Date");
                root = insert(root, 250, "Sistemas Operacionais", "Abraham Silberschatz");
                printf("5 livros de exemplo inseridos com sucesso!\n");
                break;

            case 0: // Sair
                printf("\nEncerrando o sistema...\n");
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }

        if (choice != 0) {
            printf("\nPressione ENTER para continuar...");
            getchar();
        }

    } while (choice != 0);

    printf("Obrigado por usar o Sistema de Biblioteca UEPA!\n");

    return 0;
}

