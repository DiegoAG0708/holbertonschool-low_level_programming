#include "main.h"

/**
* _memset - fills the memory with a constant byt
* @s: pointer to memory
* @b: the byte
* @n: number of bytes
*
* Return: pointer to the memory area
*/

char *_memset(char *s, char b, unsigned int n)
{

unsigned int i;

for (i = 0; i < n; i++)
{
s[i] = b;
}

return (s);
}
