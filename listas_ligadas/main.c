#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "item.h"
#include "exercicios_Feofiloff.h"
#include "functions.h"

int main() {

    int n, i;

    printf("Digite o tamanho da lista: ");
    scanf("%d", &n);

    celula *head, *t;
    head = mallocX( sizeof(celula));
    head->seg = NULL;

    //O primeiro elemento adicionado é o último elemento da lista.//
    for (i = 1; i <= n ; i++){
        t = mallocX(sizeof(celula));
        t->cont = i;
        t->seg = head->seg;
        head->seg = t;
    }
    celula *cabeca, *last;

    cabeca = mallocX(sizeof(celula));
    //Lista vazia acima//
    last = cabeca;
    last->seg = NULL;
    //O primeiro elemento adicionado é o primeiro elemento da lista//
    for (i = 1; i <= n; i++) {
        last->seg = mallocX(sizeof(celula));
        last = last->seg;
        last->cont = i;
        last->seg = NULL;
    }

    printf("Imprimindo a lista inteira: \n");
    imprima(head->seg);
    imprima(cabeca->seg);

    celula *teste;
    printf("TESTANDO:\n");
    teste = minimoI(cabeca);
    printf("%d\n", teste->cont);

    // Vetor e Lista
    celula *lista;
    lista = mallocX((n+1) * sizeof(celula));
    for (i = 0; i < n; i++) {
        //(lista+i)->seg = lista+i+1;
        lista[i].seg = &lista[i+1]; // Igual a: (lista+i)->seg = lista+i+1; // NÃO FUNCIONA
        lista[i+1].seg = NULL;
        lista[i+1].cont = i+1;
    }
    printf("Vetor e lista: ");
    imprima(lista->seg);
}
