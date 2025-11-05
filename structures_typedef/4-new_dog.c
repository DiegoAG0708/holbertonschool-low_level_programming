#include <stdlib.h>
#include "dog.h"

/*
* _strlen - returns the length of a string
* @s: string to measure
*
* Return: length of string
*/
int _strlen(char *s)
{
int len = 0;

while (s && s[len])
len++;

return (len);
}

/*
* _strcpy - copies a string to a new buffer
* @dest: destination buffer
* @src: source string
*
* Return: pointer to dest
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

/*
* new_dog - creates a new dog and copies name and owner
* @name: name of the dog
* @age: age of the dog
* @owner: owner of the dog
*
* Return: pointer to new dog_t, or NULL on failure
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
