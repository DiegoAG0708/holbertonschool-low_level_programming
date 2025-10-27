#include "main.h"
#include <stddef.h>

/**
* _strchr - returns a pointer to that position
* @s: pointer to memory
* @c:character to find
*
* Return: pointer to the first occurrence
*/

char *_strchr(char *s, char c)
{
while (*s != '\0')
{
if (*s == c)
return (s);
s++;
}
if (c == '\0')
return (s);

return (NULL);
}
