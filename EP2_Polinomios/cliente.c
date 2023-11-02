//
// Created by mreverbel on 10/29/23.
//
#include <stdio.h>
#include "polinomio.h"
#define N               ('w' - 'a' + 1)

/* Função auxiliar que descarta os próximos caracteres da entrada
   até (e incluindo) o próximo caractere '\n' */
static void descarta_resto_da_linha(FILE *entrada)
{
    int c;

    do {
        c = fgetc(entrada);
    } while (c != '\n' && c != EOF);
}

/* Função auxiliar que lê um polinômio da entrada. O polinômio vem no
   formato esperado pelo comando ":", ou seja: um inteiro não negativo
   n seguido de uma sequência de n pares de números. O primeiro número
   de cada par é o coeficiente de um termo (um double) e o segundo é o
   expoente desse termo (um inteiro não negativo). A função devolve o
   polinômio lido. */
static Polinomio le_polinomio(FILE *entrada) {

}

static void converte(char original[], char posfixa[]) {

}
static Polinomio avalia(char posfixa[], Polinomio polinomio[]) {

}


/* Função principal da calculadora */
int main(int argc, char *argv[])
{
    Polinomio var[N];  /* polinomios de 'a' a 'w' */
    FILE *entrada, *saida;
    char c1, c2;


                      /* outras variaveis, inicializacoes, etc. */


    while (fscanf(entrada, "%c", &c1) == 1) {
        if (c1 != '\n') {
            if (c1 < 'a' || c1 > 'w') {
                descarta_resto_da_linha(entrada);
                fprintf(saida, "Variavel invalida: '%c'\n", c1);
            }
            else {
                fscanf(entrada, "%c", &c2);
                switch (c2) {

                    case '?':
                         /* trata comando "?" */


                        break;
                    case ':':
                         /* trata comando ":" */


                        break;
                    case '=':
                         /* trata comando "=" */


                        break;
                    case '(':
                         /* trata comando "(" */


                        break;
                    default:
                         /* trata comando invalido */


                }
            }
        }
    }
    return 0;
}