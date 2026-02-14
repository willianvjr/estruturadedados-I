#include <stdio.h>
#include "notas.h"

void inserirNota(float vetorNotas[], int *quantidade, float novaNota) {
    if (*quantidade >= MAX_NOTAS) {
        printf("Limite de notas atingido!\n");
        return;
    }
    vetorNotas[*quantidade] = novaNota;
    (*quantidade)++;
}

void removerNota(float vetorNotas[], int *quantidade, int posicao) {
    if (posicao < 0 || posicao >= *quantidade) {
        printf("Posição inválida!\n");
        return;
    }
    for (int indice = posicao; indice < *quantidade - 1; indice++) {
        vetorNotas[indice] = vetorNotas[indice + 1];
    }
    (*quantidade)--;
}

void atualizarNota(float vetorNotas[], int quantidade, int posicao, float novaNota) {
    if (posicao < 0 || posicao >= quantidade) {
        printf("Posição inválida!\n");
        return;
    }
    vetorNotas[posicao] = novaNota;
}

void exibirNotas(float vetorNotas[], int quantidade) {
    if (quantidade == 0) {
        printf("Nenhuma nota cadastrada.\n");
        return;
    }

    float soma = 0, maior = vetorNotas[0], menor = vetorNotas[0];

    printf("\nNotas cadastradas:\n");
    for (int indice = 0; indice < quantidade; indice++) {
        printf("Posição %d: %.2f\n", indice, vetorNotas[indice]);
        soma += vetorNotas[indice];
        if (vetorNotas[indice] > maior) maior = vetorNotas[indice];
        if (vetorNotas[indice] < menor) menor = vetorNotas[indice];
    }

    printf("Média da turma: %.2f\n", soma / quantidade);
    printf("Maior nota: %.2f\n", maior);
    printf("Menor nota: %.2f\n", menor);
}