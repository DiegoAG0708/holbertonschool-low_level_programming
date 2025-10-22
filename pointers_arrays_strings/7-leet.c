#include "main.h"

/**
* leet - encodes a string into 1337
* @s: pointer to the string
*
* Return: pointer to the encoded string
*/
char *leet(char *s)
{
char letters[] = "aAeEoOtTlL";
char codes[] = "4433007711";
int i = 0, j;

while (s[i] != '\0')
{
for (j = 0; letters[j] != '\0'; j++)
{
if (s[i] == letters[j])
{
s[i] = codes[j];
break;
}
}
i++;
}

return (s);
}
