//
// Created by mreverbel on 2/4/23.
//

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "malocc.h"

typedef struct celula {
    Item conteudo;
    struct celula* prox;
} Celula;

static Celula *inicio = NULL;
static Celula *fim;

void inicia_fila(unsigned n)
{
    inicio = mallocX(sizeof(Celula));
    inicio->prox = NULL;
    fim = inicio;
}

void enfileira(Item i)
{
    fim->prox = mallocX(sizeof(Celula));
    fim = fim->prox;
    fim->conteudo = i;
    fim->prox = NULL;
}

Item desenfileira()
{
    Item i;
    Celula *morta;

    if (inicio == fim) {
        fprintf(stderr, "Erro: fila vazia!\n");
        exit(EXIT_FAILURE);
    }
    i = inicio->prox->conteudo;
    morta = inicio->prox;
    inicio->prox = morta->prox;
    if (morta == fim) {
        fim = inicio;
    }
    free(morta);
    return i;
}

int fila_vazia()
{
    return (inicio == fim);
}

void finaliza_fila()
{
    Celula *morta;

    while (inicio != NULL) {
        morta = inicio;
        inicio = inicio->prox;
        free(morta);
    }
}