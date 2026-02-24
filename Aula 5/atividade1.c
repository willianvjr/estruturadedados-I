#include <stdio.h>

int main() {
    int cont = 0;

    printf("Digite um número para definir o tamanho do vetor: ");
    scanf("%d", &cont);

    if (cont <= 0) {
        printf("Tamanho inválido!\n");
        return 1;
    }

    int vet[cont];

 
    for (int i = 0; i < cont; i++) {
        printf("Digite o valor para a posição %d: ", i);
        scanf("%d", &vet[i]);
    }

    int indice = 0;

    printf("\nDigite a posição que deseja consultar: ");
    scanf("%d", &indice);

 
    if (indice >= 0 && indice < cont) {
        printf("Valor na posição %d: %d\n", indice, vet[indice]);
    } else {
        printf("Error: posição inválida! Índice deve estar entre 0 e %d.\n", cont - 1);
    }

    return 0;
}