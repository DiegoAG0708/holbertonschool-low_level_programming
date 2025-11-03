#include <stdlib.h>

/**
* _strdup - memory pointer
*
* @str: the sring to duplicate
* Return: pointer to the duplicated string
*/

char *_strdup(char *str)

{
char *copy;
unsigned int i, length = 0;

if (str == NULL)
return (NULL);

while (str[length] != '\0')
length++;

copy = malloc(sizeof(char) * (length + 1));
if (copy == NULL)
return (NULL);

for (i = 0; i < length; i++)
copy[length] = '\0';

return (copy);

}
