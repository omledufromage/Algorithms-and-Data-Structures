#include <stdio.h>
#include <stdlib.h>

typedef struct termo {
    double coef;
    int exp;
    struct termo *next;
} Termo;
typedef struct termo *Polinomio;
void imprima(Termo *lst);
void *mallocX(size_t size);

//static void intercala(int p, int q, int r, int v[]) {
//    int *w;  // 1
//    w = malloc((r-p) * sizeof (int));  // 2
//    int i = p, j = q;  // 3
//    int k = 0;  // 4
//
//    while (i < q && j < r) {  // 5
//        if (v[i] <= v[j])  w[k++] = v[i++];  // 6
//        else  w[k++] = v[j++];  // 7
//    }  // 8
//    while (i < q)  w[k++] = v[i++];  // 9
//    while (j < r)  w[k++] = v[j++];  // 10
//    for (i = p; i < r; ++i)  v[i] = w[i-p];  // 11
//    free (w);  // 12
//}
// 1 1 3 3 5 5 6 6 7 7 12 12 0 0 2 2 4 4 8 8 9 9 10 10 11 11 13 13 0 0
static void intercala(Polinomio p, Polinomio q) {
    Termo *t, *w, *temp, *wemp;
    t = p;
    w = q;
    while (t->next != NULL && w->next != NULL) {
        if (t->exp < w->exp) {
            if (t->next->exp < w->exp) {
                t = t->next;
            } else {
                temp = t->next;
                wemp = w->next;
                t->next = w;
                w->next = temp;
                t = t->next;
                w = wemp;
            }
        } else {
            if (w->next->exp < t->exp) {
                w = w->next;
            } else {
                temp = t->next;
                wemp = w->next;
                w->next = t;
                t->next = wemp;
                w = w->next;
                t = temp;
            }
        }
    }
    if (t->next != NULL) {
        while (t != NULL) {
            if (t->exp <= w->exp) {
                if (t->next != NULL)
                    if (t->next->exp > w->exp) temp = t;
                t = t->next;
            } else {
                temp->next = w;
                w->next = t;
                w = w->next;
            }
        }
    } else if (w->next != NULL) {
        while (w != NULL) {
            if (w->exp <= t->exp) {
                if (w->next != NULL)
                    if (w->next->exp > t->exp) wemp = w;
                w = w->next;
            } else {
                wemp->next = t;
                t->next = w;
                t = t->next;
            }
        }
    }
    imprima(t);
    imprima(w);
    if (w != NULL && t != NULL) {
        printf("testing");
        if (w->exp < t->exp) {
            w->next = t;
        } else {
            t->next = w;
        }
    }
}

int main() {
    double coef;
    int exp;
    Termo *p, *q, *l1, *l2;

    scanf("%lf", &coef);
    scanf("%d", &exp);
    l1 = mallocX(sizeof(Termo));
    l1->coef = coef;
    l1->exp = exp;
    q = l1;
    scanf("%lf", &coef);
    scanf("%d", &exp);
    while(coef != 0) {
        p = mallocX(sizeof(Termo));
        p->coef = coef;
        p->exp = exp;
        q->next = p;
        q = q->next;
        scanf("%lf", &coef);
        scanf("%d", &exp);
    }
    q->next = NULL;

    scanf("%lf", &coef);
    scanf("%d", &exp);
    l2 = mallocX(sizeof(Termo));
    l2->coef = coef;
    l2->exp = exp;
    q = l2;
    scanf("%lf", &coef);
    scanf("%d", &exp);
    while(coef != 0) {
        p = mallocX(sizeof(Termo));
        p->coef = coef;
        p->exp = exp;
        q->next = p;
        q = q->next;
        scanf("%lf", &coef);
        scanf("%d", &exp);
    }
    q->next = NULL;

    imprima(l1);
    imprima(l2);

    intercala(l1, l2);
    printf("RESULTS: \n");
    if (l1->exp < l2->exp)
        imprima(l1);
    else
        imprima(l2);

}
void imprima(Termo *lst) {
    Termo *p;

    for (p = lst; p != NULL; p = p->next)
        printf("%f, %d \n", p->coef, p->exp);
    printf("\n");
}


void *mallocX(size_t size) {
    void *p;
    p = malloc(size);
    if (p == NULL) {
        printf("Socorro! Malloc devolveu NULL!\n");
        exit(EXIT_FAILURE);
    }
    return p;
}
