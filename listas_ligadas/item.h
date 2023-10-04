//
// Created by mreverbel on 10/4/23.
//

#ifndef LISTAS_LIGADAS_ITEM_H
#define LISTAS_LIGADAS_ITEM_H

typedef int Item;
typedef struct cel celula;
struct cel {
    Item cont;
    struct cel *seg;
};

#endif //LISTAS_LIGADAS_ITEM_H
