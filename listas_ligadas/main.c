#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercicios_Feofiloff.c"

void imprima(celula *lst);
void insere(int y, celula *p);

int main() {

    int n, i;
    printf("Digite o tamanho da lista: ");
    scanf("%d", &n);

    celula *head, *t, *s;
    head = malloc( sizeof(celula));
    head->seg = NULL;

    //O primeiro elemento adicionado é o último elemento da lista.//
    for (i = 1; i <= n ; i++){
        t = malloc(sizeof(celula));
        t->cont = i;
        t->seg = head->seg;
        head->seg = t;
    }
    celula *cabeca, *last;

    cabeca = malloc(sizeof(celula));
    //Lista vazia acima//
    last = cabeca;
    last->seg = NULL;
    //O primeiro elemento adicionado é o primeiro elemento da lista//
    for (i = 1; i <= n; i++) {
        last->seg = malloc(sizeof(celula));
        last = last->seg;
        last->cont = i;
        last->seg = NULL;
    }

    printf("Imprimindo a lista inteira: \n");
    imprima(head->seg);
    imprima(cabeca->seg);

    // Vetor e Lista
    celula *lista;
    lista = malloc((n+1) * sizeof(celula));
    printf("TESTANDO");
    printf(buscaF(4, head));

    for (i = 0; i < n; i++) {
        //(lista+i)->seg = lista+i+1;
        lista[i].seg = &lista[i+1]; // Igual a: (lista+i)->seg = lista+i+1; // NÃO FUNCIONA
        lista[i+1].seg = NULL;
        lista[i+1].cont = i+1;
    }
    printf("Vetor e lista: ");
    imprima(lista->seg);
}
void insere(int y, celula *p) {
    celula *nova;
    nova = malloc (sizeof (celula));
    nova->cont = y;
    nova->seg = p->seg;
    p->seg = nova;
}

void imprima(celula *lst){
    celula *p;
    for (p = lst; p != NULL; p = p->seg)
        printf("%d ", p->cont);
    printf("\n");
}

celula *busca(int x, celula *lst) {
/* Este funćão recebe um inteiro x e uma lista encadeada lst com cabeća.
 * Devolve o enderećo de uma célula que contém x ou devolve NULL se tal
 * célula não existe. */
    celula *p;
    p = lst->seg;
    while (p != NULL && p->cont != x)
        p = p->seg;
    return p;
}