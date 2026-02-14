#ifndef NOTAS_H
#define NOTAS_H

#define MAX_NOTAS 100

void inserirNota(float vetorNotas[], int *quantidade, float novaNota);
void removerNota(float vetorNotas[], int *quantidade, int posicao);
void atualizarNota(float vetorNotas[], int quantidade, int posicao, float novaNota);
void exibirNotas(float vetorNotas[], int quantidade);

#endif