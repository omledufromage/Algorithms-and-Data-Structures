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

static Polinomio intercala(Polinomio p, Polinomio q, int lambda) {
    Termo *s, *t, *w;
    t = p;
    s = q;

    struct fila {
        Termo *ini;
        Termo *fim;
    } *f;

    if (t->exp > s->exp) {
        f->ini = cria_monomio(t->coef, t->exp);
        t = t->next;
    } else if (t->exp < s->exp) {
        f->ini = cria_monomio(lambda * s->coef, s->exp);
        s = s->next;
    } else {
        f->ini = cria_monomio(t->coef + lambda * s->coef, t->exp);
        t = t->next;
        s = s->next;
    }

    for (f->fim = f->ini; s != NULL && t != NULL; f->fim->next = w, f->fim = f->fim->next) {
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
        f->fim->next = w;
        f->fim = f->fim->next;
        t = t->next;
    }
    while (s != NULL) {
        w = cria_monomio(lambda * s->coef, s->exp);
        f->fim->next = w;
        f->fim = f->fim->next;
        s = s->next;
    }
    f->fim->next = NULL;

    return f->ini;
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

    if (exp < 0) {
        printf("Não é um monômio!");
        exit(EXIT_FAILURE);
    }
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
    int lambda = 1;

    r = intercala(p, q, lambda);

    return r;
}

Polinomio subtrai(Polinomio p, Polinomio q) {
    Polinomio r;
    int lambda = -1;

    r = intercala(p, q, lambda);

    return r;
}

Polinomio multiplica(Polinomio p, Polinomio q) {

}

Polinomio divide(Polinomio p, Polinomio q) {

}

Polinomio resto(Polinomio p, Polinomio q) {

}

Polinomio oposto(Polinomio p) {
    Polinomio q, r, s, t;

    r = cria_monomio((-1)*p->coef, p->exp);
    t = r;
    for (q = p->next; q != NULL; q = q->next, t = t->next) {
        s = cria_monomio((-1)*q->coef, q->exp);
        t->next = s;
    }
    s->next = NULL;

    return r;
}

Polinomio deriva(Polinomio p) {

}

Polinomio copia(Polinomio p) {

}

int grau(Polinomio p) {
    return p->exp;
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

