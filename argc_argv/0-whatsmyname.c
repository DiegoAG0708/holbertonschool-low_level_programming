#include <stdio.h>

/**
* main - prints the program name
* @argc: argument count (unused)
* @argv: argument vector (array of strings)
*
* Return: Always 0
*/
int main(int argc, char *argv[])
{
(void)argc;  /* We don't need argc, so we silence the warning */

printf("%s\n", argv[0]);
return (0);
}
