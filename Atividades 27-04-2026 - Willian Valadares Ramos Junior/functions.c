#include <stdio.h>
#include <stdlib.h>

/*registro que reprensentará cada elemento da fila*/
struct Elemento
{
    int num;
    struct Elemento *prox;
};
typedef struct Elemento Elemento;

/*registro do tipo Fila contento dois ponteiros do tipo nó para controlar a fila*/
struct Fila
{
    struct Elemento *inicio; /*aponta para o elemento do início da fila*/
    struct Elemento *fim;    /*aponta para o elemento do fim da fila*/
};
typedef struct Fila Fila;

/*ponteiro auxiliar*/
Elemento *aux;

Fila *cria_fila()
{
    Fila *fi = (Fila *)malloc(sizeof(Fila));
    if (fi != NULL)
    {
 
        fi->fim = NULL;
        fi->inicio = NULL;
    }
    return fi;
}

void insere_elemento(Fila *fi)
{
 
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    printf("\nDigite o numero a ser inserido na fila: ");
    scanf("%d", &novo->num);
    novo->prox = NULL;
 
    if (fi->inicio == NULL)
    {
        fi->inicio = novo;
        fi->fim = novo;
 
    }
    else
    {
        fi->fim->prox = novo;
        fi->fim = novo;
    }
    printf("\nNumero inserido na fila!");
    
}

void consulta_fila(Fila *fi)
{
    if (fi->inicio == NULL)
    {
        printf("\nFila Vazia!!");
    }
    else
    {
        aux = fi->inicio;
        do
        {
            printf("\n %d ", aux->num);
            aux = aux->prox;
        } while (aux != NULL);
    }
 
}

void remove_elemento_fila(Fila *fi)
{
    if (fi->inicio == NULL)
    {
        printf("\nFila Vazia!!");
    }
    else
    {
        aux = fi->inicio;
        printf("\n%d removido!", fi->inicio->num);
        fi->inicio = fi->inicio->prox;
        free(aux);
    }

}
