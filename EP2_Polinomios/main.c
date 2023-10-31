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
    q = cria_monomio(3, 2);
    p = copia(q); // PROBLEM WITH COPIA

    s = soma(q, p);
    for (r = s; r != NULL; r = r->next) {
        printf("%.2fx^%d", r->coef, r->exp);
        if (r->next != NULL)
            printf(" + ");
    }

    printf("\nRESTO\n\n");
    r = resto(p, q);
    for (p = r; p != NULL; p = p->next) {
        printf("%.2fx^%d", p->coef, p->exp);
        if (p->next != NULL)
            printf(" + ");
        else
            printf("\n");
    }
    libera(r);

    r = resto(q, s);
    for (p = r; p != NULL; p = p->next) {
        printf("%.2fx^%d", p->coef, p->exp);
        if (p->next != NULL)
            printf(" + ");
        else
            printf("\n");
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
    printf("\nf(3): %f", calcula(s, 3));

    printf("\nGRAU Q: %d", grau(s));
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
    printf("GRAU S: %d\n", grau(s));
    printf("f(5): %f\n", calcula(s, 5));

    Termo *temp;
    temp = cria_monomio(1, 0);
    libera(r);
    r = multiplica(s, temp);
    for (p = r; p != NULL; p = p->next) {
        printf("%.2fx^%d", p->coef, p->exp);
        if (p->next != NULL)
            printf(" + ");
        else
            printf("\n");
    }
    libera(r);
    r = multiplica(temp, q);
    for (p = r; p != NULL; p = p->next) {
        printf("%.2fx^%d", p->coef, p->exp);
        if (p->next != NULL)
            printf(" + ");
        else
            printf("\n");
    }

    libera(r);
    r = multiplica(s, q);
    for (p = r; p != NULL; p = p->next) {
        printf("%.2fx^%d", p->coef, p->exp);
        if (p->next != NULL)
            printf(" + ");
        else
            printf("\n");
    }
    libera(r);

    printf("DIVISÃO\n\n");
    r = divide(q, s);
    for (p = r; p != NULL; p = p->next) {
        printf("%.2fx^%d", p->coef, p->exp);
        if (p->next != NULL)
            printf(" + ");
        else
            printf("\n");
    }
    libera(r);

    r = divide(s, q);
    for (p = r; p != NULL; p = p->next) {
        printf("%.2fx^%d", p->coef, p->exp);
        if (p->next != NULL)
            printf(" + ");
        else
            printf("\n");
    }
    libera(r);
    printf("\nRESTO\n\n");
    r = resto(s, q);
    for (p = r; p != NULL; p = p->next) {
        printf("%.2fx^%d", p->coef, p->exp);
        if (p->next != NULL)
            printf(" + ");
        else
            printf("\n");
    }
    libera(r);

    r = resto(q, s);
    for (p = r; p != NULL; p = p->next) {
        printf("%.2fx^%d", p->coef, p->exp);
        if (p->next != NULL)
            printf(" + ");
        else
            printf("\n");
    }

    return 0;
}

