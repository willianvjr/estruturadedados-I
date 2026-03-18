#include <stdio.h>

int main() {

    int matriz[3][3];
    int i, j;
    float soma;
    float somasetor;
    char *setores[3] = {"Almoxarifado", "T.I", "Comercial"};
    char *produtos[3][3] = {
    {"Limpol", "Kiboa", "Bom ar"},
    {"Ram DDR5", "Core Ultra", "Mouse"},
    {"Produto A", "Produto B", "Produto C"}
    };

int estoque[3][3] = {
    {50, 20, 10},
    {50, 25, 12},
    {20, 30, 7}
    };

    // Impressão da matriz
    printf("\nMatriz digitada:\n");
    
    for(i = 0; i < 3; i++) {
        somasetor = 0;
        for(j = 0; j < 3; j++) {
            printf(" Produto: %s",produtos[i][j]);
            printf(" Setor: %s", setores[i]) ;
            printf (" Estoque: %i\n", estoque[i][j]);
            soma = soma + estoque[i][j];
            somasetor += estoque[i][j];
            
        }
        
        printf("\n");
        printf("Soma do setor %s %.2f", setores[i],somasetor);
        printf("\n");
    }

printf ("A Soma das linhas e: %.2f", soma);
    
}
