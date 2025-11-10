#include "function_pointers.h"
#include <stddef.h>

/**
* print_name - Calls a function to print a new name
* @name: The name to print
* @f: Pointer to a function that
*
*/

void print_name(char *name, void (*f)(char *))

{
if (name == NULL || f == NULL)
return;

f(name);
}
