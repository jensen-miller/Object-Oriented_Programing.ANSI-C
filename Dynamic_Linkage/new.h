#ifndef NEW_H
#define NEW_H

/** Allocation and Freeing Functions */

void * new (const void * _class, ...);
void delete (void * self);



/** Template callers that adapt to common methods of objects. */

int differ(const void * self, const void * b);
void * clone(const void * self);
size_t sizeOf(const void * self);

#endif