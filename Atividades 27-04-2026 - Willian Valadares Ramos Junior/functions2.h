#ifndef FILA_H
#define FILA_H

typedef struct Elemento Elemento;
typedef struct Fila Fila;

// Protótipos das funções
Fila *cria_fila();
void insereElementos(Fila *fi);
void consultaFila(Fila *fi);
void removeFila(Fila *fi);
void tempoTotal(Fila *fi);

#endif