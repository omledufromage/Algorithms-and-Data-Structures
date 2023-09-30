#ifndef __FILA_H__

#include "item.h"

typedef struct fila *Fila;
// When making a typedef of an adress (*), no need to define the struct here.

Fila cria_fila(int capacidade);
void enfileira(Fila f, Item i);
Item desenfileira(Fila f);
int fila_vazia(Fila f);
void destroi_fila(Fila f);

#define __FILA_H__
#endif