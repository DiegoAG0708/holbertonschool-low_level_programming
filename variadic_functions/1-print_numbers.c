#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
*print_numbers - Prints numbers separated by a string
*@separator: The string to print between numbers
*@n: The number of integers passed to the function
*
*Description: This function prints each integer followed by the separator.
*If separator is NULL, it is skipped. A newline is printed at the end.
*/
void print_numbers(const char *separator, const unsigned int n, ...)
{
va_list args;
unsigned int i;

va_start(args, n);

for (i = 0; i < n; i++)
{
printf("%d", va_arg(args, int));
if (separator != NULL && i < n - 1)
printf("%s", separator);
}

va_end(args);
printf("\n");
}
