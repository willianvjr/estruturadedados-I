#include <stdio.h>

int main() {
    int tamanho;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("Tamanho inválido!\n");
        return 1;
    }

    int vet[tamanho];

    for (int i = 0; i < tamanho; i++) {
        printf("Digite o valor da posição %d: ", i);
        scanf("%d", &vet[i]);
    }

     int maior = vet[0];
     int menor = vet[0];


    for (int i = 1; i < tamanho; i++) {
         if (vet[i] > maior) {
            maior = vet[i];
        }

         if (vet[i] < menor) {
            menor = vet[i];
        }
    }

        printf("\nMaior valor: %d\n", maior);
     printf("Menor valor: %d\n", menor);

    return 0;
}