#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 10000001
#define M 10001

typedef struct cel celula;
struct cel {
    char nucleobase;
    struct cel *next;
    struct cel *mirror;
};

int origin(int x, int va[], int vb[], int i, bool *direction);
void reverse(celula *v, celula *w, int va[], int vb[], int i);
void imprima(celula *lst, size_t n);
void *mallocX(size_t size);

int main() {
    int nops, *a, *b, i;
    static char st[N];

    scanf("%d \n", &nops);
    scanf(" %s\n", st);
    a = mallocX((nops+1)*sizeof(int));
    b = mallocX((nops+1)*sizeof(int));
    a[0] = -1;
    b[0] = -1;
    for (i = 1; i <= nops; i++) {
        scanf("%d %d", &a[i], &b[i]);
        if (a[i] >= b[i]) {
            fprintf(stderr, "Erro na entrada!\n");
            return EXIT_FAILURE;
        }
    }

    celula *v, *w;
    char *pst;

    size_t n, m;

    n = strlen(st);

    v = mallocX((N+1)*sizeof(celula)); //Pode usar n também ao invés de N
    w = mallocX((N+1)*sizeof(celula)); // "

    pst = st;
    for (i = 0, m = n; i <= n; i++, m--) {
        v[i].next = &v[i+1];
        w[m].next = &w[m-1];
        v[i+1].nucleobase = pst[i];
        w[i+1].nucleobase = pst[i];
        v[i].mirror = &w[i];
        w[i].mirror = &v[i];
    }
    v[n].next = &v[0];
    w[0].next = &w[n];

    for (i = 1; i <= nops; i++) {
//        imprima(v->next, n);
        reverse(v, w, a, b, i);
    }

    imprima(v->next, n);

    return 0;
}
int origin(int x, int va[], int vb[], int i, bool *direction) {
    if (i == 0)
        return x;
    if (x >= va[i] && x <= vb[i]) {
        x = vb[i] + va[i] - x;
        *direction = !*direction;
    }
    return origin(x, va, vb, i-1, direction);
}

void reverse(celula *v, celula *w, int va[], int vb[], int i) {
    int a, b;
    bool direction;
    celula *p, *q, *mainA, *copyA, *mainB, *copyB;

    direction = true;
    a = origin(va[i], va, vb, i - 1, &direction);
    if (direction == true) {
        mainA = v + a;
        copyA = w + a;
    } else {
        mainA = w + a;
        copyA = v + a;
    }
    direction = true;
    b = origin(vb[i], va, vb, i - 1, &direction);
    if (direction == true) {
        mainB = v + b;
        copyB = w + b;
    }
    else {
        mainB = w + b;
        copyB = v + b;
    }

    p = mainB->next;
    q = copyA->next;

    copyB->mirror->next->mirror->next = mainA;
    mainA->mirror->next->mirror->next = copyB;
    mainB->next = q;
    copyA->next = p;
}

void imprima(celula *lst, size_t n) {
    celula *p;
    int i;

    for (p = lst, i = 0; i < n; p = p->next, i++)
        printf("%c", p->nucleobase);
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
