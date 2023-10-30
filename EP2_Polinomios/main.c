#include <stdio.h>
#include "polinomio.h"

typedef struct termo {
    double coef;
    int exp;
    struct termo *next;
} Termo;

int main() {
    int i, N = 4;
    Polinomio q, p, r, s;
    r = NULL, s = NULL, p = NULL, q = NULL;

    printf("Hello, World!\n");

    r = cria_monomio(1, 6);
    s = soma(cria_monomio(1, 5), cria_monomio(1, 4));
    for (p = s; p != NULL; p = p->next)
        printf("%.2fx^%d + \n", p->coef, p->exp);
    q = soma(r, s);
    for (p = q; p != NULL; p = p->next)
        printf("%.2fx^%d + ", p->coef, p->exp);

    libera(q);
    libera(p);
    libera(r);
    libera(s);


    return 0;
}

