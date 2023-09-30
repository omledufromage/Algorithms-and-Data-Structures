#include <stdio.h>
#define N 5
#define FIND 1

int busca(int x, int v[], int n){
    /* Esta funćão recebe um número x e um vetore v[0..n-1] com n >= 0 e
     * devolve k no intervalo 0..n-1 tal que v[k] == x. Adota-se a convenćão
     * de devolver -1 se o x não estiver no vetor. No caso de x ocorrer múltiplas
     * vezes, a funćão devolve a última ocorrência de x em v. */

    int k;
    k = n - 1;

    /* invariante -> no início de cada iteraćão, v[k+1..n-1] não contêm x. */
    while (k >= 0 && v[k] != x) // A ordem aqui importa! "while(v[k] != x && k >= 0)" causaria o erro de examinar v[-1]. //
        k -= 1;
    return k;
}
/* (Funćão eficiente e elegante.) */

int buscaR(int x, int v[], int n) {

}

int remove(int k, int v[], int n) {

}

int removeR(int k, int v[], int n) {

}

int insere(int k, int y, int v[], int n) {

}

int insereR(int k, int y, int v[], int n) {

}

int removeZeros(int v[], int n) {

}

int removeZeroesR(int v[], int n) {

}

int main() {

    int v[N], i;

    printf("Digite %d números: ", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    i = busca(FIND, v, N);
    if (i != -1)
        printf("O número %d encontra-se na posićào v[%d].\n", FIND, i, i);
    else
        printf("O número %d não encontra-se neste vetor.\n", FIND, i);
}
