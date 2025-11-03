#include <stdlib.h>

/**
* _strdup - returns a pointer to a newly allocated space in memory,
*           which contains a copy of the string given as a parameter
* @str: the string to duplicate
*
* Return: pointer to the duplicated string, or NULL if str is NULL or malloc fails
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
copy[i] = str[i];

copy[length] = '\0';

return (copy);
}
