//
// Created by mreverbel on 10/3/23.
//
#include <stdio.h>
#include "exercicios_Feofiloff.h"

// 1)
// Critique a funcão abaixo.  Ao receber uma lista encadeada com cabeça e um inteiro x, ela promete devolver o
// endereço de uma célula com conteúdo x. Se tal célula não existe, promete devolver NULL:

celula *buscaF(int x, celula *ini) {
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

// A funcão não funciona pois devolve a celula seguinta a desejada. Além disso, a solućão não é elegante, uma vez que a
// variável 'achou' pode ser inteiramente descartada e que podemos dar 'return p' mesmo quando não achamos x, considerando
// que p será NULL. Mas ela incrementa p = p->seg depois que achou a celula correta, e acaba devolvendo a celula errada:
celula *buscaComCabeca(int x, celula *ini) {
    celula *p;
    p = ini->seg;
    while (p != NULL && p->cont != x) // "Avaliaćão em curto circuito". Nem olha para a segunda avaliaćão se a primeira for falsa.
        p = p->seg;
    return p;
}
// 2)
// Escreva uma versão da funćão busca para listas sem cabeća:
celula *buscaSemCabeca(int x, celula *ini) {
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
celula *minimoI(celula *ini) {
    celula *p, *x;
    p = ini->seg;
    if (p == NULL) {
        printf("Lista vazia!");
        return NULL;
    } // Tem algum jeito de evitar este if?
    x = p;
    for (p = p->seg; p != NULL; p = p->seg) {
        if (p->cont < x->cont)
            x = p;
    }
    return x;
}
celula *minimoR(celula *ini) {
    celula *p, *x, *y;
    p = ini->seg;
    x = NULL;
    if (p != NULL) {
        x = p;
        if (p->seg == NULL)
            return x;
        else {
            y = minimoR(p);
            if (y->cont < x->cont)
                x = y;
        }
    }
    return x;
}

// 4)
//