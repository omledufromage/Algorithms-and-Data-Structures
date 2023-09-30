//
// Created by mreverbel on 2/4/23.
//

#ifndef __POLINOMIO_H__

typedef struct termo *Polinomio;

Polinomio cria_monomio(double coef, int exp);
Polinomio soma(Polinomio p, Polinomio q);
Polinomio subtrai(Polinomio p, Polinomio q);
Polinomio multiplica(Polinomio p, Polinomio q);
Polinomio divide(Polinomio p, Polinomio q);
Polinomio resto(Polinomio p, Polinomio q);
Polinomio oposto(Polinomio p);
Polinomio deriva(Polinomio p);
Polinomio copia(Polinomio p);
int grau(Polinomio p);
double calcula(Polinomio p, double x);
void imprime(Polinomio p, FILE *arq);
void libera(Polinomio p);

#define __POLINOMIO_H__
#endif
