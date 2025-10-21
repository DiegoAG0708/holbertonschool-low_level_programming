#include "main.h"

/**
* print_rev - prints a string in reverse followed by a newline
* @s: pointer to the string
*
* Return: nothing
*/
void print_rev(char *s)
{
int len = 0;

/* First, find the length of the string */
while (s[len] != '\0')
{
len++;
}

/* Now print characters in reverse */
while (len > 0)
{
len--;
_putchar(s[len]);
}

_putchar('\n');
}
