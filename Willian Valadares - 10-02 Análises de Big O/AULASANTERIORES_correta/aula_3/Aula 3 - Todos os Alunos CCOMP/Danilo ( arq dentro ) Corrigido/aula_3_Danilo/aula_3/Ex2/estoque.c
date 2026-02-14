#include <stdio.h>
#include <string.h>
#include "estoque.h"

void cadastrarProduto(int codigos[], char nomes[][MAX_NOME], int quantidades[], int *qtd) {
    if (*qtd >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    int codigo;
    printf("Digite o código do produto: ");
    scanf("%d", &codigo);
    while (getchar() != '\n');

    for (int i = 0; i < *qtd; i++) {
        if (codigos[i] == codigo) {
            printf("Código já cadastrado!\n");
            return;
        }
    }

    codigos[*qtd] = codigo;

    printf("Digite o nome do produto: ");
    fgets(nomes[*qtd], MAX_NOME, stdin);
    nomes[*qtd][strcspn(nomes[*qtd], "\n")] = '\0'; 

    int quantidade;
    printf("Digite a quantidade: ");
    scanf("%d", &quantidade);

    if (quantidade < 0) {
        printf("Quantidade não pode ser negativa!\n");
        return;
    }

    quantidades[*qtd] = quantidade;
    (*qtd)++;

    printf("Produto cadastrado com sucesso!\n");
}

void atualizarQuantidade(int codigos[], int quantidades[], int qtd) {
    int codigo;
    printf("Digite o código do produto: ");
    scanf("%d", &codigo);

    for (int i = 0; i < qtd; i++) {
        if (codigos[i] == codigo) {
            int novaQtd;
            printf("Digite a nova quantidade: ");
            scanf("%d", &novaQtd);

            if (novaQtd < 0) {
                printf("Quantidade não pode ser negativa!\n");
                return;
            }

            quantidades[i] = novaQtd;
            printf("Quantidade atualizada!\n");
            return;
        }
    }

    printf("Produto não encontrado!\n");
}

void removerProduto(int codigos[], char nomes[][MAX_NOME], int quantidades[], int *qtd) {
    int codigo;
    printf("Digite o código do produto a remover: ");
    scanf("%d", &codigo);

    for (int i = 0; i < *qtd; i++) {
        if (codigos[i] == codigo) {
            for (int j = i; j < *qtd - 1; j++) {
                codigos[j] = codigos[j + 1];
                strcpy(nomes[j], nomes[j + 1]);
                quantidades[j] = quantidades[j + 1];
            }
            (*qtd)--;
            printf("Produto removido!\n");
            return;
        }
    }

    printf("Produto não encontrado!\n");
}

void listarProdutos(int codigos[], char nomes[][MAX_NOME], int quantidades[], int qtd) {
    if (qtd == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("\n=== Lista de Produtos ===\n");
    for (int i = 0; i < qtd; i++) {
        printf("Código: %d | Nome: %s | Quantidade: %d\n",
               codigos[i], nomes[i], quantidades[i]);
    }
}