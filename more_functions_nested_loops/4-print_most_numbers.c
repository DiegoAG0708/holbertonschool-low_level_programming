#include "main.h"

/**
* print_most_numbers - prints numbers from 0 to 9 except 2 and 4
*/
void print_most_numbers(void)
{
char c[] = "01356789\n";
int i = 0;

while (c[i] != '\0')
{
_putchar(c[i]);
i++;
}
}
