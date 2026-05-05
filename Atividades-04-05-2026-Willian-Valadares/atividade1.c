#include <stdio.h>
#include <stdlib.h>

/* =========================
   Estrutura do Nó
========================= */
typedef struct No {
    int valor;
    struct No *prox;
} No;

/* =========================
   Estrutura da Fila
========================= */
typedef struct {
    No *inicio;
    No *fim;
} Fila;

/* =========================
   Criar fila
========================= */
Fila* criarFila() {
    Fila *fila = (Fila*) malloc(sizeof(Fila));

    fila->inicio = NULL;
    fila->fim = NULL;

    return fila;
}

/* =========================
   Verificar se está vazia
========================= */
int estaVazia(Fila *fila) {
    return (fila->inicio == NULL);
}

/* =========================
   Inserir elemento (enqueue)
========================= */
void enqueue(Fila *fila, int valor) {

    No *novo = (No*) malloc(sizeof(No));

    novo->valor = valor;
    novo->prox = NULL;

    /* Se a fila estiver vazia */
    if (estaVazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

/* =========================
   Remover elemento (dequeue)
========================= */
int dequeue(Fila *fila) {

    if (estaVazia(fila)) {
        printf("Fila vazia!\n");
        return -1;
    }

    No *temp = fila->inicio;
    int valor = temp->valor;

    fila->inicio = fila->inicio->prox;

    /* Se a fila ficou vazia */
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(temp);

    return valor;
}

/* =========================
   Exibir elementos da fila
========================= */
void exibirFila(Fila *fila) {

    if (estaVazia(fila)) {
        printf("Fila vazia!\n");
        return;
    }

    No *aux = fila->inicio;

    printf("Fila: ");

    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }

    printf("\n");
}

/* =========================
   Contar elementos
========================= */
int contarElementos(Fila *fila) {

    int contador = 0;

    No *aux = fila->inicio;

    while (aux != NULL) {
        contador++;
        aux = aux->prox;
    }

    return contador;
}

/* =========================
   Consultar primeiro elemento
========================= */
int primeiroElemento(Fila *fila) {

    if (estaVazia(fila)) {
        printf("Fila vazia!\n");
        return -1;
    }

    return fila->inicio->valor;
}

/* =========================
   Programa principal
========================= */
int main() {

    Fila *fila = criarFila();

    enqueue(fila, 10);
    enqueue(fila, 20);
    enqueue(fila, 30);

    exibirFila(fila);

    printf("Quantidade de elementos: %d\n", contarElementos(fila));

    printf("Primeiro elemento: %d\n", primeiroElemento(fila));

    printf("Elemento removido: %d\n", dequeue(fila));

    exibirFila(fila);

    return 0;
}