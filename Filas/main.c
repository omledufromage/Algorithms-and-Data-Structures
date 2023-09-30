#include <stdio.h>
#include "item.h"
#include "fila.h"

#define N 20

int main()
{
    Item i;
    Fila f1, f2;

    f1 = cria_fila(N);

    for (i = 0; i < N; i++)
        enfileira(f1, i);

    f2 = cria_fila(N);

    while (!fila_vazia(f1))
        enfileira(f2, desenfileira(f1));

    destroi_fila(f1);

    while (!fila_vazia(f2))
        printf("%d\n", desenfileira(f2));

    destroi_fila(f2);

    return 0;
}