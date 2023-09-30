#include <stdio.h>
#include "mallocc.h"

void *mallocc(size_t nbytes)
{
    void *ptr;

    ptr = malloc(nbytes);
    if (ptr == NULL) {
        fprintf(stderr, "Socorro! malloc devolveu NULL!\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}