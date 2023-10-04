//
// Created by mreverbel on 10/4/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
void *mallocX(size_t nbytes) {
    void *ptr;

    ptr = malloc(nbytes);
    if (ptr == NULL) {
        fprintf(stderr, "Socorro! malloc devolveu NULL!\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}
void insere(int y, celula *p) {
    celula *nova;
    nova = mallocX(sizeof (celula));
    nova->cont = y;
    nova->seg = p->seg;
    p->seg = nova;
}

void imprima(celula *lst){
    celula *p;
    for (p = lst; p != NULL; p = p->seg)
        printf("%d ", p->cont);
    printf("\n");
}

celula *busca(int x, celula *lst) {
/* Este funćão recebe um inteiro x e uma lista encadeada lst com cabeća.
 * Devolve o enderećo de uma célula que contém x ou devolve NULL se tal
 * célula não existe. */
    celula *p;
    p = lst->seg;
    while (p != NULL && p->cont != x)
        p = p->seg;
    return p;
}
