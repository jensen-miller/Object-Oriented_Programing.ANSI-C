#include "new.h"

#include <assert.h>
#include <stdlib.h>

void * new (const void * type, ...)
{
    /*  get the size of the type provided */
    const size_t size = * (const size_t *) type;

    /*  allocate memory for a new object of size(type) */
    void * p = calloc(1, size);

    assert(p);
    return p;
}


void delete(void * item)
{
    /*  recycle the item's memory */
    free(item);
}