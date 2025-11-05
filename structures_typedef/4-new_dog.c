#include <stdlib.h>
#include "dog.h"

/**
*_strlen - Calculates the length of a string
*@s: The string to measure
*
*Return: The number of characters in the string
*/
int _strlen(char *s)
{
int len = 0;

while (s && s[len])
len++;

return (len);
}

/**
*_strcpy - Copies a string from source to destination
*@dest: The buffer to copy into
*@src: The string to copy
*
*Return: Pointer to the destination buffer
*/
char *_strcpy(char *dest, char *src)
{
int i = 0;

while (src && src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';

return (dest);
}

/**
*new_dog - Creates a new dog and stores copies of name and owner
*@name: The name of the dog
*@age: The age of the dog
*@owner: The owner of the dog
*
*Return: Pointer to the new dog_t structure, or NULL on failure
*
*Description: This function allocates memory for a new dog_t structure,
*copies the name and owner strings into newly allocated memory,
*and assigns them to the structure. If any allocation fails,
*it frees all previously allocated memory and returns NULL.
*/
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *d;
char *name_copy, *owner_copy;
int name_len, owner_len;

d = malloc(sizeof(dog_t));
if (d == NULL)
return (NULL);

name_len = _strlen(name);
owner_len = _strlen(owner);

name_copy = malloc(name_len + 1);
if (name_copy == NULL)
{
free(d);
return (NULL);
}
_strcpy(name_copy, name);

owner_copy = malloc(owner_len + 1);
if (owner_copy == NULL)
{
free(name_copy);
free(d);
return (NULL);
}
_strcpy(owner_copy, owner);

d->name = name_copy;
d->age = age;
d->owner = owner_copy;

return (d);
}
