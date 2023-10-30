#include <stdio.h>
#include <stdlib.h>
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
    Termo *s, *t, *w, *first, *last;
    t = p;
    s = q;

    if (t == NULL && s == NULL)
        return NULL;

    if ((s == NULL && t != NULL) || t->exp > s->exp ) {
        first = cria_monomio(t->coef, t->exp);
        t = t->next;
    } else if ((t == NULL && s != NULL) || t->exp < s->exp || t == NULL) {
        first = cria_monomio((lambda * s->coef), s->exp);
        s = s->next;
    } else {
        first = cria_monomio(t->coef + lambda * s->coef, t->exp);
        t = t->next;
        s = s->next;
    }

    for (last = first; t != NULL && s != NULL; last->next = w, last = last->next) {
        if (t->exp > s->exp) {
            w = cria_monomio(t->coef, t->exp);
            t = t->next;
        } else if (t->exp < s->exp) {
            w = cria_monomio(lambda * s->coef, s->exp);
            s = s->next;
        } else {
            w = cria_monomio(t->coef + lambda * s->coef, t->exp);
            t = t->next;
            s = s->next;
        }
    }
    while (t != NULL) {
        w = cria_monomio(t->coef, t->exp);
        t = t->next;
        last->next = w;
        last = last->next;
    }
    while (s != NULL) {
        w = cria_monomio(lambda * s->coef, s->exp);
        s = s->next;
        last->next = w;
        last = last->next;
    }
    last->next = NULL;

    return first;
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
    int lambda = 1;

    if (p != NULL && q != NULL)
        r = intercala(p, q, lambda);
    else if (p == NULL)
        r = copia(q);
    else
        r = copia(p);

    return r;
}

Polinomio subtrai(Polinomio p, Polinomio q) {
    Polinomio r;
    int lambda = -1;

    if (p != NULL && q != NULL)
        r = intercala(p, q, lambda);
    else if (p == NULL)
        r = copia(q);
    else
        r = copia(p);

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

Polinomio deriva(Polinomio p) {
    Polinomio q, s , first = NULL, last;

    if (p->exp != 0) {
        first = cria_monomio(p->exp * p->coef, p->exp - 1);
        last = first;

        for (q = p->next; q != NULL; q = q->next) {
            if (q->exp != 0) {
                s = cria_monomio(q->exp * q->coef, q->exp - 1);
                last->next = s;
                last = last->next;
            }
        }
    }
    s->next = NULL;

    return first;
}

Polinomio copia(Polinomio p) {

    return soma(p, NULL);
}
/*    Polinomio q, s, first, last;

    if (p == NULL)
        return NULL;

    first = cria_monomio(p->coef, p->exp);
    last = first;
    if (p->next == NULL)
        return first;

    for (q = p->next; q != NULL; q = q->next, last = last->next) {
        s = cria_monomio(q->coef, q->exp);
        last->next = s;
    }
    s->next = NULL;

    return first;
}
*/

int grau(Polinomio p) {
    if (p != NULL)
        return p->exp;
    else
        return 0;
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

