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
        reciclado = mallocX(sizeof(Termo)); // Diferenca entre sizeof(Termo) e sizeof(Polinomio)?  Termo é um struct. Polinomio é um ponteiro (menor).
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

    last = first;
    while (p != NULL && q != NULL)
        if (p->exp > q->exp) {
            w = cria_monomio(p->coef, p->exp);
            p = p->next;
            last->next = w;
            last = last->next;
        } else if (p->exp < q->exp) {
            w = cria_monomio(lambda * q->coef, q->exp);
            q = q->next;
            last->next = w;
            last = last->next;
        } else {
            if (p->coef + lambda * q->coef != 0) {
                w = cria_monomio(p->coef + lambda * q->coef, p->exp);
                last->next = w;
                last = last->next;
            }
            p = p->next;
            q = q->next;
        }
    for (;p != NULL; p = p->next, last->next = w, last = last->next)
        w = cria_monomio(p->coef, p->exp);
    for (;q != NULL; q = q->next, last->next = w, last = last->next)
        w = cria_monomio(lambda * q->coef, q->exp);

    return first->next;
}

static Polinomio multiplica_por_monomio(Polinomio p, double coef, int exp) {
    Termo head;
    Polinomio s, first = &head, last;

    first->next = NULL;
    for (last = first; p != NULL && coef != 0; last->next = s, p = p->next, last = last->next) {
        s = cria_monomio(coef * p->coef, exp + p->exp);
    }

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
    Polinomio s, t = NULL, sum = NULL;

    for (; q != NULL; q = q->next) {
        s = multiplica_por_monomio(p, q->coef, q->exp);
        sum = soma(t, s);
        libera(s);
        libera(t);
        t = sum;
    }

    return sum;
}

Polinomio divide(Polinomio p, Polinomio q) {
    Polinomio s, t, p_original = p, temp = NULL, quot = NULL;
    double coef;
    int exp;

    if (q == NULL) {
        printf("Cannot divide by 0!\n");
        exit(EXIT_FAILURE);
    }

    while (p != NULL && p->exp >= q->exp) {
        coef = p->coef / q->coef;
        exp = p->exp - q->exp;
        t = cria_monomio(coef, exp);
        s = multiplica_por_monomio(q, coef, exp);

        temp = quot;
        quot = soma(quot, t); //
        libera(t);
        libera(temp);

        temp = p;
        p = subtrai(p, s); //
        if (temp != p_original)
            libera(temp);
        libera(s);
    }

    return quot;
}

Polinomio resto(Polinomio p, Polinomio q) {
    Polinomio s, temp = NULL;
    double coef;
    int exp;

    p = copia(p);

    if (q == NULL) {
        printf("Cannot divide by 0!\n");
        exit(EXIT_FAILURE);
    }

    while (p != NULL && p->exp >= q->exp) {
        coef =  p->coef / q->coef;
        exp = p->exp - q->exp;
        s = multiplica_por_monomio(q, coef, exp);

        temp = p;
        p = subtrai(p, s); // cp_p não está virando NULL quando deveria!
        libera(s);
        if (temp != p)
            libera(temp);
    }

    return p;
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
    // s->next = NULL;

    return first->next;
}

Polinomio copia(Polinomio p) {

    return soma(p, NULL);
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
    //arq = fopen("Output.txt", "w");// "w" means that we are going to write on this file
    for (;p != NULL; p = p->next) {
        fprintf(arq, "%.2fx^%d", p->coef, p->exp);
        if (p->next != NULL)
            fputs(" + ", arq);
    }
    fputs("\n", arq);
    //fclose(arq);
}

void libera(Polinomio p) {
    Termo *i;
    while (p != NULL) {
        i = p;
        p = p->next;
        libera_termo(i);
    }
}

