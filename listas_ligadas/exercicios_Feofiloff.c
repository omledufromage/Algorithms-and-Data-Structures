//
// Created by mreverbel on 10/3/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel celula;
struct cel {
    int cont;
    struct cel *seg;
};
// 1)
// Critique a funcão abaixo.  Ao receber uma lista encadeada com cabeça e um inteiro x, ela promete devolver o
// endereço de uma célula com conteúdo x. Se tal célula não existe, promete devolver NULL:

celula *busca(int x, celula *ini) {
    int achou;
    celula *p;
    achou = 0;
    p = ini->seg;
    while (p != NULL && !achou) {
        if (p->cont == x) achou = 1;
        p = p->seg; }
    if (achou) return p;
    else return NULL;
}

// A funcão acima deve funcionar, mas a solućão não é elegante, uma vez que a variável 'achou' pode ser inteiramente
// descartada e que podemos dar 'return p' mesmo quando não achamos x, considerando que p será NULL:
celula *busca_com_cabeca(int x, celula *ini) {
    celula *p;
    p = ini->seg;
    while (p != NULL && p->cont != x)
        p = p->seg;
    return p;
}
// 2)
// Escreva uma versão da funćão busca para listas sem cabeća:
celula *busca_sem_cabeca(int x, celula *ini) {
    celula *p;
    // Preciso de um ´if statement' para o caso de ini apontar para NULL? Depende da ordem dentro do While!
    p = ini;
    while (p != NULL && p->cont != x) //p->conteudo não existe se p for NULL.
        p = p->seg;
    return p;
}

// 3)
// Escreva uma função que encontre uma célula de conteúdo mínimo. Faça duas versões: uma iterativa e uma recursiva.
// (Com cabeca)
celula *minimo_iterativa(celula *ini) {
    celula *p;
    int x;
    p = ini->seg;
    if (p == NULL) {
        printf("Lista vazia!");
        return NULL;
    } // Tem algum jeito de evitar este if?
    x = p->cont;
    for (p = p->seg; p != NULL; p = p->seg) {
        if (p->cont < x)
            x = p->cont;
    }
    return x;
}
celula *minimo_recursiva(celula *ini) {
    celula *p;
    p = ini->seg;
    int x = NULL, y;
    if (p != NULL)
        x = p->cont;
        if (p->seg == NULL)
            return x;
    y = minimo_recursiva(p->seg);
    if (y < x)
        x = y;
    return x;
}

// 4)
//