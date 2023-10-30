#include <stdio.h>
#include "polinomio.h"

typedef struct termo {
    double coef;
    int exp;
    struct termo *next;
} Termo;

int main() {
    int i;
    Polinomio q, p, r, s, t;

    printf("FIRST: ");
    q = cria_monomio(3, 0);
    p = copia(q); // PROBLEM WITH COPIA

    s = soma(q, p);
    libera(q);
    libera(p);
    for (r = s; r != NULL; r = r->next) {
        printf("%.2fx^%d", r->coef, r->exp);
        if (r->next != NULL)
            printf(" + ");
    }

    printf("\nSECOND: ");
    q = cria_monomio(1, 1);
    p = cria_monomio(1, 3);

    t = subtrai(q,p);
    libera(q);
    libera(p);
    for (r = t; r != NULL; r = r->next) {
        printf("%.2fx^%d", r->coef, r->exp);
        if (r->next != NULL)
            printf(" + ");
    }

    printf("\nBIG SUM: ");
    q = soma(s, t);
    for (p = q; p != NULL; p = p->next) {
        printf("%.2fx^%d", p->coef, p->exp);
        if (p->next != NULL)
            printf(" + ");
    }

    printf("\nOPPOSITE: ");
    libera(s);
    s = oposto(q);
    for (p = s; p != NULL; p = p->next) {
        printf("%.2fx^%d", p->coef, p->exp);
        if (p->next != NULL)
            printf(" + ");
    }

printf("\nGRAU: %d", grau(s));
printf("\nDERIVATIVE: ");
    libera(s);
    s = deriva(q);
    for (p = s; p != NULL; p = p->next) {
        printf("%.2fx^%d", p->coef, p->exp);
        if (p->next != NULL)
            printf(" + ");
        else
            printf("\n");
    }
    printf("GRAU: %d\n", grau(s));
    libera(q);
    libera(p);
    libera(r);
    libera(s);

    return 0;
}

