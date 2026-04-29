#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions2.h"

int main()
{
    Fila *fi = cria_fila();

    for (int i = 0; i < 5; i++)
    {
        printf("Novo cliente! Inclua-o na fila: \n");
        insereElementos(fi);
    }

    printf("\n");

    printf("\nO tempo total de atendimento antes dos clientes serem atendidos: \n");
    tempoTotal(fi);
    printf("\n");

    // Vamos atender 3 clientes
    for (int i = 0; i < 3; i++)
    {
        removeFila(fi);   
    }

    printf("\n");
    printf("Consultando clientes a serem atendidos... \n");
    consultaFila(fi);
    printf("\nO tempo total de atendimento dos clientes ainda não atendidos e: \n");
    tempoTotal(fi);
    return 0;   
}