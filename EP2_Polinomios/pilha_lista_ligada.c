//
// Created by mreverbel on 2/4/23.
//

#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "pilha.h"

/* O topo da pilha e' o inicio de uma lista encadeada sem cabeca. */
static Termo *lista_livre = NULL;

void inicia_pilha(int n)
{
}

void finaliza_pilha()
{
    Termo *morta;

    while (lista_livre != NULL) {
        morta = lista_livre;
        lista_livre = lista_livre->next;
        free(morta);
    }
}

int pilha_vazia()
{
    return (lista_livre == NULL);
}

void empilha(Termo *novo) {
    Termo *i;

    i = novo;
    while (i->next != NULL)
        i = i->next;
    i->next = lista_livre;
    lista_livre = novo;
}

Termo desempilha()
{
    Termo *reciclado;

    if (lista_livre == NULL) {
        fprintf(stderr, "Erro: pilha vazia!\n");
        exit(EXIT_FAILURE);
    }
    reciclado = lista_livre;
    lista_livre = lista_livre->next;
    return *reciclado;
}

int espia_topo()
{
    if (lista_livre == 0) {
        fprintf(stderr, "Erro: pilha vazia!\n");
        exit(EXIT_FAILURE);
    }
    return lista_livre->exp;
}

