#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct elemento
{
 int num_identificacao;
 float tempo_atendimento;
 struct elemento *prox;    
} Elemento;

struct Fila
{
    struct elemento *inicio; /*aponta para o elemento do início da fila*/
    struct elemento *fim;    /*aponta para o elemento do fim da fila*/
};
typedef struct Fila Fila;

Fila *cria_fila(){
 Fila *fi = (Fila *)malloc(sizeof(Fila));
 if (fi != NULL)
 {
  fi -> fim = NULL;
  fi -> inicio = NULL;
 }
 return fi;
}



void insereElementos(Fila *fi){
 Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
 printf("Digite um número de identificação de usuário para ser inserido na fila: \n");
 scanf("%d", &novo->num_identificacao);
 printf("Qual é o tempo previsto para o atendimento desse cliente? ( Em minutos ): \n");
 scanf("%f", &novo->tempo_atendimento);
 novo->prox = NULL;

    if (fi->inicio == NULL){
        fi ->inicio = novo;
        fi ->fim = novo;
    }
    else
    {
        fi->fim->prox = novo;
        fi->fim = novo;
    }
    
 printf("Numero de identificacao do cliente inserido na fila! \n");
}

Elemento *aux;

void consultaFila (Fila *fi){
    if (fi->inicio == NULL){
        printf("Fila está vazia! Não tem nada para consultar...");
    }else{
        aux = fi -> inicio;
        do
        {
            printf("cliente %d \n", aux->num_identificacao);

            aux = aux->prox;
        } while (aux != NULL);
        
    }

}

void removeFila (Fila *fi){
    if (fi->inicio == NULL){
        printf("Fila está vazia! Não tem nada para consultar...");
    }else{
        aux = fi->inicio;
        printf("cliente %d foi atendido! Removendo da fila... \n", fi->inicio->num_identificacao);
        fi->inicio = fi->inicio->prox;
        free(aux);
    }

}

float tempoTotal(Fila *fi) {
    Elemento *aux = fi->inicio;
    float total = 0;

    while (aux != NULL) {
        total += aux->tempo_atendimento;
        aux = aux->prox;
    }

    printf("%.2f minutos. \n", total);
}
