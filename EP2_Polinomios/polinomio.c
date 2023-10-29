
#include <stdio.h>
#include <stdlib.h>
#include "mallocc.h"
#include "polinomio.h"
#include "pilha.h"
#include "item.h"


static Termo *lista_livre = NULL;

static void s_intercala(int p, int q, int r, int v[]) {
    int i, j, *w;
    w = malloc((r-p) * sizeof (int));

    for (i = p; i < q; ++i) w[i-p] = v[i];
    for (j = q; j < r; ++j) w[r-p+q-j-1] = v[j];
    i = 0; j = r-p-1;
    for (int k = p; k < r; ++k)
        if (w[i] <= w[j]) v[k] = w[i++];
        else v[k] = w[j--];
    free (w);
}

static void intercala(int p, int q, int r, int v[]) {
    int *w;  // 1
    w = malloc((r-p) * sizeof (int));  // 2
    int i = p, j = q;  // 3
    int k = 0;  // 4

    while (i < q && j < r) {  // 5
        if (v[i] <= v[j])  w[k++] = v[i++];  // 6
        else  w[k++] = v[j++];  // 7
    }  // 8
    while (i < q)  w[k++] = v[i++];  // 9
    while (j < r)  w[k++] = v[j++];  // 10
    for (i = p; i < r; ++i)  v[i] = w[i-p];  // 11
    free (w);  // 12
}

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
static Termo *aloca_termo() {
    Polinomio p;

    if (lista_livre == NULL)
        p = mallocX(sizeof(Polinomio));
    else
        p = desempilha();
    return
}

static void libera_termo(Termo *p) {

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

}
