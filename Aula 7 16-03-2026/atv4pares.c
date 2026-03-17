#include <stdio.h>

int main() {

    int matriz[3][3];
    int i, j;

    // Leitura da matriz
    printf("Digite os valores da matriz 3x3:\n");

    int contpar = 0;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            if (matriz[i][j] %2 == 0){
                contpar++;
            }
        }

        
    }

    // Impressão da matriz
    printf("\nMatriz digitada:\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("Quantidade de numeros pares: %i", contpar);

}