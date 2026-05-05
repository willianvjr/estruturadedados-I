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
   Inserir normal
========================= */
void enqueue(Fila *fila, int valor) {

    No *novo = (No*) malloc(sizeof(No));

    novo->valor = valor;
    novo->prox = NULL;

    if (estaVazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

/* =========================
   Remover elemento
========================= */
int dequeue(Fila *fila) {

    if (estaVazia(fila)) {
        return -1;
    }

    No *temp = fila->inicio;

    int valor = temp->valor;

    fila->inicio = fila->inicio->prox;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(temp);

    return valor;
}

/* =========================
   Exibir fila
========================= */
void exibirFila(Fila *fila) {

    No *aux = fila->inicio;

    printf("Fila: ");

    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }

    printf("\n");
}

/* ==================================================
   1. FILA COM PRIORIDADE
   Menor valor = maior prioridade
   Mantém ordem crescente
================================================== */
void enqueuePrioridade(Fila *fila, int valor) {

    No *novo = (No*) malloc(sizeof(No));

    novo->valor = valor;
    novo->prox = NULL;

    /* Inserção no início */
    if (estaVazia(fila) || valor < fila->inicio->valor) {

        novo->prox = fila->inicio;
        fila->inicio = novo;

        if (fila->fim == NULL) {
            fila->fim = novo;
        }

        return;
    }

    /* Procurar posição correta */
    No *atual = fila->inicio;

    while (atual->prox != NULL &&
           atual->prox->valor < valor) {

        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;

    /* Atualizar fim */
    if (novo->prox == NULL) {
        fila->fim = novo;
    }
}

/* ==================================================
   2. INVERTER FILA
   Utilizando apenas manipulação da própria fila
================================================== */
void inverterFila(Fila *fila) {

    No *anterior = NULL;
    No *atual = fila->inicio;
    No *proximo = NULL;

    fila->fim = fila->inicio;

    while (atual != NULL) {

        proximo = atual->prox;

        atual->prox = anterior;

        anterior = atual;
        atual = proximo;
    }

    fila->inicio = anterior;
}

/* ==================================================
   3. COPIAR FILA
================================================== */
Fila* copiarFila(Fila *filaOriginal) {

    Fila *novaFila = criarFila();

    No *aux = filaOriginal->inicio;

    while (aux != NULL) {

        enqueue(novaFila, aux->valor);

        aux = aux->prox;
    }

    return novaFila;
}

/* ==================================================
   4. CONCATENAR FILAS
================================================== */
Fila* concatenarFilas(Fila *fila1, Fila *fila2) {

    Fila *fila3 = criarFila();

    No *aux = fila1->inicio;

    /* Copia fila1 */
    while (aux != NULL) {

        enqueue(fila3, aux->valor);

        aux = aux->prox;
    }

    /* Copia fila2 */
    aux = fila2->inicio;

    while (aux != NULL) {

        enqueue(fila3, aux->valor);

        aux = aux->prox;
    }

    return fila3;
}

/* =========================
   Programa principal
========================= */
int main() {

    /* =================================
       FILA COM PRIORIDADE
    ================================= */
    Fila *prioridade = criarFila();

    enqueuePrioridade(prioridade, 30);
    enqueuePrioridade(prioridade, 10);
    enqueuePrioridade(prioridade, 20);
    enqueuePrioridade(prioridade, 5);

    printf("Fila com prioridade:\n");
    exibirFila(prioridade);

    /* =================================
       INVERTER FILA
    ================================= */
    inverterFila(prioridade);

    printf("\nFila invertida:\n");
    exibirFila(prioridade);

    /* =================================
       COPIAR FILA
    ================================= */
    Fila *copia = copiarFila(prioridade);

    printf("\nCopia da fila:\n");
    exibirFila(copia);

    /* =================================
       CONCATENAR FILAS
    ================================= */
    Fila *filaA = criarFila();
    Fila *filaB = criarFila();

    enqueue(filaA, 1);
    enqueue(filaA, 2);
    enqueue(filaA, 3);

    enqueue(filaB, 4);
    enqueue(filaB, 5);
    enqueue(filaB, 6);

    Fila *concatenada = concatenarFilas(filaA, filaB);

    printf("\nFila concatenada:\n");
    exibirFila(concatenada);

    return 0;
}
