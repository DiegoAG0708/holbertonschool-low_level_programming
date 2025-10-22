#include "main.h"

/**
* _strncpy - copies a string up to n characters
* @dest: pointer to the destination buffer
* @src: pointer to the source string
* @n: maximum number of characters to copy
*
* Return: pointer to the destination buffer
*/
char *_strncpy(char *dest, char *src, int n)
{
int i = 0;

while (i < n && src[i] != '\0')
{
dest[i] = src[i];
i++;
}

while (i < n)
{
dest[i] = '\0';
i++;
}

return (dest);
}
