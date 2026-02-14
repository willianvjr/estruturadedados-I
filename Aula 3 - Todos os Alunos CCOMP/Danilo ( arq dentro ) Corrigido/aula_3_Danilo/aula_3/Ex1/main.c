#include <stdio.h>
#include "notas.h"

int main() {
    float vetorNotas[MAX_NOTAS];
    int quantidade = 0;
    int opcao;

    do {
        printf("\n===== MENU NOTAS =====\n");
        printf("1 - Inserir nota\n");
        printf("2 - Remover nota\n");
        printf("3 - Atualizar nota\n");
        printf("4 - Exibir notas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                float novaNota;
                printf("Digite a nota: ");
                scanf("%f", &novaNota);
                inserirNota(vetorNotas, &quantidade, novaNota);
                break;
            }
            case 2: {
                int posicao;
                printf("Digite a posição da nota a remover: ");
                scanf("%d", &posicao);
                removerNota(vetorNotas, &quantidade, posicao);
                break;
            }
            case 3: {
                int posicao;
                float novaNota;
                printf("Digite a posição da nota a atualizar: ");
                scanf("%d", &posicao);
                printf("Digite a nova nota: ");
                scanf("%f", &novaNota);
                atualizarNota(vetorNotas, quantidade, posicao, novaNota);
                break;
            }
            case 4:
                exibirNotas(vetorNotas, quantidade);
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