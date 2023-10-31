#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mallocc.h"
#include "polinomio.h"
#define N 100

typedef struct termo {
    double coef;
    int exp;
    struct termo *next;
} Termo;

static Termo *lista_livre = NULL;
static int n_lista = 0;

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
        printf("Increase size (N) if this warning is too frequent!");
    }
}

static Polinomio intercala(Polinomio p, Polinomio q, int lambda) {
    Termo head;
    Termo *w, *first = &head, *last;

    first->next = NULL;

    for (last = first; p != NULL && q != NULL; last->next = w, last = last->next)
        if (p->exp > q->exp) {
            w = cria_monomio(p->coef, p->exp);
            p = p->next;
        } else if (p->exp < q->exp) {
            w = cria_monomio(lambda * q->coef, q->exp);
            q = q->next;
        } else {
            w = cria_monomio(p->coef + lambda * q->coef, p->exp);
            p = p->next;
            q = q->next;
        }
    for (;p != NULL; p = p->next, last->next = w, last = last->next)
        w = cria_monomio(p->coef, p->exp);
    for (;q != NULL; q = q->next, last->next = w, last = last->next)
        w = cria_monomio(lambda * q->coef, q->exp);
    last->next = NULL;

    return first->next;
}

Polinomio cria_monomio(double coef, int exp) {
    Polinomio p;

    if (exp < 0) {
        printf("Não é um monômio!");
        exit(EXIT_FAILURE);
    }
    if (coef == 0) {
        p = NULL;
    }
    else {
        p = aloca_termo();
        p->coef = coef;
        p->exp = exp;
        p->next = NULL;
    }
    return p;
}

Polinomio soma(Polinomio p, Polinomio q) {
    Polinomio r;

    r = intercala(p, q, 1);

    return r;
}

Polinomio subtrai(Polinomio p, Polinomio q) {
    Polinomio r;

    r = intercala(p, q, -1);

    return r;
}

Polinomio multiplica(Polinomio p, Polinomio q) {

}

Polinomio divide(Polinomio p, Polinomio q) {

}

Polinomio resto(Polinomio p, Polinomio q) {

}

Polinomio oposto(Polinomio p) {

    return subtrai(NULL, p);
}
/*
Polinomio oposto(Polinomio p) {
    Termo head;
    Polinomio s, first = &head, last;

    first->next = NULL;
    for (last = first; p != NULL; p = p->next, last->next = s, last = last->next) {
        s = cria_monomio((-1)*p->coef, p->exp);
    }
    s->next = NULL;

    return first->next;
}
*/

Polinomio deriva(Polinomio p) {
    Termo head;
    Polinomio s, first = &head, last;

    first->next = NULL;
    for (last = first; p != NULL;  p = p->next) {
        if (p->exp != 0) {
            s = cria_monomio(p->exp * p->coef, p->exp - 1);
            last->next = s;
            last = last->next;
        }
    }
    s->next = NULL;

    return first->next;
}

Polinomio copia(Polinomio p) {

    return soma(NULL, p);
}
/*
Polinomio copia(Polinomio p) {
    Termo head;
    Polinomio s, first = &head, last;

    first->next = NULL;
    for (last = first; p != NULL; p = p->next, last->next = s, last = last->next) {
        s = cria_monomio(p->coef, p->exp);
    }
    s->next = NULL;

    return first->next;
}
*/

int grau(Polinomio p) {
    if (p != NULL)
        return p->exp;
    else
        return 0;
}

double calcula(Polinomio p, double x) {
    double total = 0;

    for (; p != NULL; p = p->next)
        total = total + p->coef * pow(x, p->exp);

    return total;
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

