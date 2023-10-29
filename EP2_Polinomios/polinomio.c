
#include <stdio.h>
#include <stdlib.h>
#include "mallocc.h"
#include "item.h"
#include "polinomio.h"

static Termo *lista_livre = NULL;

/*
static void intercala(Polinomio p, Polinomio q) {
    Termo *t, *w, *r;

    while (t->next != NULL && w->next != NULL) {
        if (t->exp < w->exp) {
            while ( t->next != NULL && t->next->exp < w->exp )
                t = t->next;
            r = t->next;
            t->next = w;
            t = r;
        }
        else if (t->exp > w->exp) {
            while (w->next != NULL && w->next->exp < t->exp )
                w = w->next;
            r = w->next;
            w->next = t;
            w = r;
        }
    }
}
*/
static Termo *aloca_termo() {
    Termo *reciclado;

    if (lista_livre == NULL)
        reciclado = mallocX(sizeof(Polinomio));
    else {
        if (lista_livre == NULL) {
            fprintf(stderr, "Erro: pilha vazia!\n");
            exit(EXIT_FAILURE);
        }
        reciclado = lista_livre;
        lista_livre = lista_livre->next;
    }
    return reciclado;
}

static void libera_termo(Termo *novo) {

    novo->next = lista_livre;
    lista_livre = novo;
}

Polinomio cria_monomio(double coef, int exp) {
    Polinomio p;

    p = mallocX(sizeof(Polinomio));

    if (coef == 0) {
        p = NULL;
    }
    else {
        p->coef = coef;
        p->exp = exp;
        p->next = NULL;
    }
    return p;
}

Polinomio soma(Polinomio p, Polinomio q) {
    Polinomio r;


    return r;
}

Polinomio subtrai(Polinomio p, Polinomio q) {

}

Polinomio multiplica(Polinomio p, Polinomio q) {

}

Polinomio divide(Polinomio p, Polinomio q) {

}

Polinomio resto(Polinomio p, Polinomio q) {

}

Polinomio oposto(Polinomio p) {

}

Polinomio deriva(Polinomio p) {

}

Polinomio copia(Polinomio p) {

}

int grau(Polinomio p) {

}

double calcula(Polinomio p, double x) {

}

void imprime(Polinomio p, FILE *arq) {

}

void libera(Polinomio p) {
    Termo *i;

    while (p->next != NULL) {
        i = p;
        p = p->next;
        libera_termo(i);
    }
}

