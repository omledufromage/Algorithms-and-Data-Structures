//
// Created by mreverbel on 10/4/23.
//

#ifndef LISTAS_LIGADAS_FUNCTIONS_H
#define LISTAS_LIGADAS_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

void *mallocX(size_t nbytes);
void imprima(celula *lst);
void insere(int y, celula *p);
celula *busca(int x, celula *lst);

#endif //LISTAS_LIGADAS_FUNCTIONS_H
