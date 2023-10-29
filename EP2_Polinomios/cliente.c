//
// Created by mreverbel on 10/29/23.
//
#include <stdio.h>
#include "item.h"
#include "pilha.h"
#include "mallocc.h"

#define N 20

int main()
{
    int i;
    Termo p, *q;
    inicia_pilha(N);

    for (i = 0; i < N; i++) {

        q = mallocX(sizeof(Termo));
        q->exp = i;
        q->next = NULL;
        empilha(q);
    }

    while (!pilha_vazia()) {
        p = desempilha();
        printf("%d ", p.exp);
        if (!pilha_vazia())
            printf("%d\n", espia_topo());
    }
    finaliza_pilha();

    return 0;
}