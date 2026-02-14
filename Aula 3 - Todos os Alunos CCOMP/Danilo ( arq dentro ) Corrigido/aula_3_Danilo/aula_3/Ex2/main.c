#include <stdio.h>
#include "estoque.h"

int main() {
    int codigos[MAX_PRODUTOS];
    char nomes[MAX_PRODUTOS][MAX_NOME];
    int quantidades[MAX_PRODUTOS];
    int qtd = 0;
    int opcao;

    do {
        printf("\n===== MENU ESTOQUE =====\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Atualizar Quantidade\n");
        printf("3 - Remover Produto\n");
        printf("4 - Listar Produtos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                cadastrarProduto(codigos, nomes, quantidades, &qtd);
                break;
            case 2:
                atualizarQuantidade(codigos, quantidades, qtd);
                break;
            case 3:
                removerProduto(codigos, nomes, quantidades, &qtd);
                break;
            case 4:
                listarProdutos(codigos, nomes, quantidades, qtd);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}