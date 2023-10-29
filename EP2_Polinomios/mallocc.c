//
// Created by mreverbel on 2/4/23.
//

#include <stdio.h>
#include "mallocc.h"

void *mallocX(size_t size) {
    void *p;
    p = malloc(size);
    if (p == NULL) {
        printf("Socorro! Malloc devolveu NULL!\n");
        exit(EXIT_FAILURE);
    }
    return p;
}
