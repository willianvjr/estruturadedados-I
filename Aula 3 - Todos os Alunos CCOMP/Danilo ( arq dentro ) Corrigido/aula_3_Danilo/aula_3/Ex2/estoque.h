#ifndef ESTOQUE_H
#define ESTOQUE_H

#define MAX_PRODUTOS 100
#define MAX_NOME 50

void cadastrarProduto(int codigos[], char nomes[][MAX_NOME], int quantidades[], int *qtd);
void atualizarQuantidade(int codigos[], int quantidades[], int qtd);
void removerProduto(int codigos[], char nomes[][MAX_NOME], int quantidades[], int *qtd);
void listarProdutos(int codigos[], char nomes[][MAX_NOME], int quantidades[], int qtd);

#endif