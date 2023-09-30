#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "fila.h"
#include "mallocc.h"

typedef struct celula {
    Item conteudo;
    struct celula* prox;
} Celula;

struct fila {
    Celula *ini;   /* inicio da fila */
    Celula *fim;   /* fim da fila */
};

Fila cria_fila(int capacidade)
{
    Fila f;

    if (capacidade <= 1) {
        fprintf(stderr, "Erro: capacidade da fila deve ser maior que 1!\n");
        exit(EXIT_FAILURE);
    }
    f = mallocc(sizeof(struct fila));
    f->ini = mallocc(sizeof(Celula));
    f->ini->prox = NULL;
    f->fim = f->ini;
    return f;
}

void enfileira(Fila f, Item i)
{
    f->fim->prox = mallocc(sizeof(Celula));
    f->fim = f->fim->prox;
    f->fim->conteudo = i;
    f->fim->prox = NULL;
}

Item desenfileira(Fila f)
{
    Item i;
    Celula *morta;

    if (f->ini == f->fim) {
        fprintf(stderr, "Erro: fila vazia!\n");
        exit(EXIT_FAILURE);
    }
    i = f->ini->prox->conteudo;
    morta = f->ini->prox;
    f->ini->prox = morta->prox;
    if (morta == f->fim) {
        f->fim = f->ini;
    }
    free(morta);
    return i;
}

int fila_vazia(Fila f)
{
    return (f->ini == f->fim);
}

void destroi_fila(Fila f)
{
    Celula *p, *morta;

    p = f->ini;
    while (p != NULL) {
        morta = p;
        p = p->prox;
        free(morta);
    }
}
