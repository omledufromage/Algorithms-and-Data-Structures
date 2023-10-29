//
// Created by mreverbel on 2/4/23.
//
#ifndef __PILHA_H__
#include "item.h"

void inicia_pilha(int n);
void finaliza_pilha();
int pilha_vazia();
void empilha(Termo *novo);
Termo desempilha();
int espia_topo();

#define __PILHA_H__
#endif
