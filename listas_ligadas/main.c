#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel celula;
struct cel {
    int cont;
    struct cel *seg;
};

void imprima(celula *lst);
void insere(int y, celula *p);

celula *buscaF(int x, celula *ini) {
    int achou;
    celula *p;
    achou = 0;
    p = ini->seg;
    while (p != NULL && !achou) {
        if (p->cont == x) achou = 1;
        p = p->seg; }
    if (achou) return p;
    else return NULL;
}

// A funcão acima deve funcionar, mas a solućão não é elegante, uma vez que a variável 'achou' pode ser inteiramente
// descartada e que podemos dar 'return p' mesmo quando não achamos x, considerando que p será NULL:
celula *buscaComCabeca(int x, celula *ini) {
    celula *p;
    p = ini->seg;
    while (p != NULL && p->cont != x)
        p = p->seg;
    return p;
}
// 2)
// Escreva uma versão da funćão busca para listas sem cabeća:
celula *buscaSemCabeca(int x, celula *ini) {
    celula *p;
    // Preciso de um ´if statement' para o caso de ini apontar para NULL? Depende da ordem dentro do While!
    p = ini;
    while (p != NULL && p->cont != x) //p->conteudo não existe se p for NULL.
        p = p->seg;
    return p;
}

// 3)
// Escreva uma função que encontre uma célula de conteúdo mínimo. Faça duas versões: uma iterativa e uma recursiva.
// (Com cabeca)
celula *minimoI(celula *ini) {
    celula *p, *x;
    p = ini->seg;
    if (p == NULL) {
        printf("Lista vazia!");
        return NULL;
    } // Tem algum jeito de evitar este if?
    x = p;
    for (p = p->seg; p != NULL; p = p->seg) {
        if (p->cont < x->cont)
            x = p;
    }
    return x;
}
celula *minimoR(celula *ini) {
    celula *p, *x, *y;
    p = ini->seg;
    x = NULL;
    if (p != NULL) {
        x = p;
        if (p->seg == NULL)
            return x;
        else {
            y = minimoR(p);
            if (y->cont < x->cont)
                x = y;
        }
    }
    return x;
}


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

    celula *teste;
    printf("TESTANDO:\n");
    teste = buscaComCabeca(4, head);
    printf("%d\n", &teste->cont);

    // Vetor e Lista
    celula *lista;
    lista = malloc((n+1) * sizeof(celula));
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