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

    s = soma(cria_monomio(1, 1), cria_monomio(1, 1));
    for (p = s; p != NULL; p = p->next)
        printf("%.2fx^%d +", p->coef, p->exp);

    printf("\n");

    r = soma(cria_monomio(1, 5),cria_monomio(1, 4));
    q = subtrai(s, r);
    for (p = q; p != NULL; p = p->next)
        printf("%.2fx^%d + ", p->coef, p->exp);

    printf("\n");

    libera(s);
    s = oposto(q);
    libera(q);
    for (p = s; p != NULL; p = p->next)
        printf("%.2fx^%d + ", p->coef, p->exp);
    libera(p);
    libera(r);
    libera(s);

    return 0;
}

