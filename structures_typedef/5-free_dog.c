#include <stdlib.h>
#include "dog.h"

/**
*free_dog - Frees memory allocated for a dog_t structure
*@d: Pointer to the dog structure to free
*
*Description: This function frees the memory allocated for the
*name and owner strings, and then frees the structure itself.
*If the pointer is NULL, nothing is done.
*/
void free_dog(dog_t *d)
{
if (d == NULL)
return;

free(d->name);
free(d->owner);
free(d);
}
