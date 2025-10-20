#include "main.h"

/**
* print_numbers - prints numbers from 0 to 9
*/
void print_numbers(void)
{
char c[] = "0123456789\n";
int i = 0;

while (c[i] != '\0')
{
_putchar(c[i]);
i++;
}
}
