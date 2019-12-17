#include <stdlib.h>
#include <assert.h>

#include "new.h"
#include "class.h"


/**
 * @brief Dynamically allocates memory for an object.
 * @param[in] _class The class descriptor.
 * @param[in] ... Arguments to pass to constructor (if available).
 * @returns A pointer to the new object instance.
 */
void * 
new (const void * _class, ...)
{
    /* Reinterpret descriptor pointer. */
    const struct Class * class = _class;

    /* Allocate an object instance. Initialize the object
     *  to all zeros to prevent a false-positive of ctor. */
    void * p_class_inst = calloc(1, class->size);
    assert(p_class_inst);

    /* Reinterpret the class instance as a Class pointer reference.
     *  In doing so, we are dereferencing the class instance, and point
     *  it to its class descriptor. This works due to the first data
     *  member of any object being the descriptor pointer.
     */
    *(const struct Class **)p_class_inst = class;
    
    /* Attempt to use the constructor (if it exists) */
    if (class->ctor)
    {
        /* Pass in constructor arguments. */
        va_list ctor_args;
        va_start(ctor_args, _class);
        p_class_inst = class->ctor(p_class_inst, &ctor_args);
        va_end(ctor_args);
    }
    /* Return the instance of the class. */
    return p_class_inst;
}


/** 
 * @brief Delete a dynamically allocated object.
 * @param[in] self The object to free. Calls destructor if available.
 */
void 
delete (void* self)
{
    const struct Class ** p_class = self;
    /* Validate object, check for descriptor, check
     *  for destructor. */
    if (self && *p_class && (*p_class)->dtor)
    {
        /* Allow the destructor to free any memory
         *  allocated by the object's data members */
        self = (*p_class)->dtor(self);
    }
    /* Free the instance of the class. */
    free(self);
}


int
differ(const void * self, const void * b)
{
    /* Get a constant pointer to the class descriptor. The
     *  const-ness of the pointer protects against
     *  changing the object's descriptor pointer. */
    const struct Class * const * const_p_class = self;

    assert(self && *const_p_class && (*const_p_class)->differ);
    return (*const_p_class)->differ(self, b);
}

void *
clone(const void * self)
{
    const struct Class * const * const_p_self = self;

    assert(self && *const_p_self && (*const_p_self)->clone);
    return (*const_p_self)->clone(const_p_self);
}



size_t
sizeOf (const void * self)
{
    const struct Class * const * const_p_self = self;

    assert(self && *const_p_self);
    return (*const_p_self)->size;
}