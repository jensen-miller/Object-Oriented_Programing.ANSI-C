#include <stdio.h>

#include "new.h"
#include "Object.h"
#include "Set.h"


int main()
{
	//	create a new Set object
    void * s = new(Set);

	//	add an object to the set
    void * a = add(s, new(Object));

	//	add an object to the set
    void * b = add(s, new(Object));

	//	create an individual instance of an object
    void * c = new(Object);


    if (contains(s, a) && contains(s, b))
        puts("ok");

    if (contains(s, c))
        puts("contains?");

    if (differ(a, add(s, a)))
        puts("differ?");

    if (contains(s, drop(s,a)))
        puts("drop?");

    delete(drop(s, b));
    delete(drop(s, c));
    
    return 0;
}