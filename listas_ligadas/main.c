#include <stdio.h>
#include <string.h>

#include "item.h"
#include "exercicios_Feofiloff.h"
#include "functions.h"

int main() {

    int n, prim, ult, i;

    printf("Type the first and last numbers of the list: ");
    scanf("%d", &prim);
    scanf("%d", &ult);
    if (ult < prim) {
        n = prim;
        prim = ult;
        ult = n;
    }

    celula *head, *t;
    head = mallocX( sizeof(celula));
    head->seg = NULL;

    //O primeiro elemento adicionado é o último elemento da lista.//
    for (i = prim; i <= ult ; i++){
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
    for (i = prim; i <= ult; i++) {
        last->seg = mallocX(sizeof(celula));
        last = last->seg;
        last->cont = i;
        last->seg = NULL;
    }

    printf("Imprimindo a lista inteira: \n");
    imprima(head->seg);
    imprima(cabeca->seg);

    celula *teste;
    printf("The smallest term in the list is:\n");
    teste = minimoI(cabeca);
    printf("%d\n", teste->cont);

    printf("The smallest term in the list is:\n");
    teste = minimoR(head);
    printf("%d\n", teste->cont);

    printf("Would you like to find out whether a specific number is in the list? Enter the number: ");
    scanf("%d", &n);
    teste = buscaComCabeca(n, cabeca);
    if (teste != NULL)
        printf("%d is in the list!\n\n", teste->cont);
    else
        printf("%d is not in the list.\n\n", n);

    printf("Would you like to find out whether another number is in the list? Enter the number: ");
    scanf("%d", &n);
    teste = buscaSemCabeca(n, head);
    if (teste != NULL)
        printf("%d is in the list!\n\n", teste->cont);
    else
        printf("%d is not in the list.\n\n", n);

    // Vetor e Lista (just an exercise)
    celula *lista;
    n = ult - prim;
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
