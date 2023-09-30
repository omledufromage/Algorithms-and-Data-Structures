//
// Created by mreverbel on 2/4/23.
//
#ifndef __FILA_H__

void inicia_fila(unsigned capacidade);
void enfileira(Item i);
Item desenfileira();
int fila_vazia(); /* devolve 0 ou 1 */
void finaliza_fila();

#define __FILA_H__
#endif
