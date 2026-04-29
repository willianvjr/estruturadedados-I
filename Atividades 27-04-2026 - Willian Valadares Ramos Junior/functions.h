#ifndef FILA_H
#define FILA_H

typedef struct Elemento Elemento;
typedef struct Fila Fila;

// Protótipos das funções
Fila *cria_fila();
void insere_elemento(Fila *fi);
void consulta_fila(Fila *fi);
void remove_elemento_fila(Fila *fi);


#endif