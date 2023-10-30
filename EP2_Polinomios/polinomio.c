#include <stdio.h>
#include <stdlib.h>
#include "mallocc.h"
#include "polinomio.h"
#define N 100
#define TRUE 1
#define FALSE 0

typedef struct termo {
    double coef;
    int exp;
    struct termo *next;
} Termo;

static Termo *lista_livre = NULL;
static int n_lista = 0;

static int sum = TRUE;
static Polinomio intercala(Polinomio p, Polinomio q) {
    Termo *s, *t, *w, *r;
    t = p;
    s = q;
    r = NULL; // r é o topo da pilha, que servirá de ponteiro para o polinomio intercalado, mas em ordem reversa.

    while (s != NULL && t != NULL) {
        if (t->exp > s->exp) {
            w = cria_monomio(t->coef, t->exp);
            w->next = r;
            r = w;
            t = t->next;
        } else if (t->exp < s->exp) {
            w = cria_monomio(s->coef, s->exp);
            w->next = r;
            r = w;
            s = s->next;
        } else {
            if (sum == TRUE) {
                w = cria_monomio(s->coef + t->coef, t->exp);
            }
            else {
                w = cria_monomio((-1) * (s->coef + t->coef), t->exp);
            }
            w->next = r;
            r = w;
            t = t->next;
            s = s->next;
        }
    }
    while (t != NULL) {
        w = cria_monomio(t->coef, t->exp);
        w->next = r;
        r = w;
        t = t->next;
    }
    while (s != NULL) {
        w = cria_monomio(s->coef, s->exp);
        w->next = r;
        r = w;
        s = s->next;
    }
    s = NULL;
    for (t = r; t != NULL; t = t->next) {
        w = cria_monomio(t->coef, t->exp);
        w->next = s;
        s = w;
    }

    return s;
}

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
        n_lista--;
    }
    return reciclado;
}

static void libera_termo(Termo *novo) {

    if (n_lista < N) {
        novo->next = lista_livre;
        lista_livre = novo;
        n_lista++;
    } else {
        free(novo);
        printf("Increase size if this warning is too frequent!");
    }
}

Polinomio cria_monomio(double coef, int exp) {
    Polinomio p;

    p = aloca_termo();

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

    sum = TRUE;
    r = intercala(p, q);

    return r;
}

Polinomio subtrai(Polinomio p, Polinomio q) {
    Polinomio r;

    sum = FALSE;
    r = intercala(p, q);

    return r;
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
    while (p != NULL) {
        i = p;
        p = p->next;
        libera_termo(i);
    }
}

