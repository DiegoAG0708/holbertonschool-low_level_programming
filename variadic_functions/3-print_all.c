#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
*print_all - Prints anything based on format specifiers
*@format: A string of format specifiers
*
*Description: Format specifiers:
* c: char
* i: integer
* f: float
* s: string (prints (nil) if NULL)
* Any other character is ignored.
* Prints a newline at the end.
*/
void print_all(const char * const format, ...)
{
va_list args;
int i = 0;
char *str;
char *sep = "";

va_start(args, format);

while (format && format[i])
{
if (format[i] == 'c')
{
printf("%s%c", sep, va_arg(args, int));
}
if (format[i] == 'i')
{
printf("%s%d", sep, va_arg(args, int));
}
if (format[i] == 'f')
{
printf("%s%f", sep, va_arg(args, double));
}
if (format[i] == 's')
{
str = va_arg(args, char *);
if (str == NULL)
str = "(nil)";
printf("%s%s", sep, str);
}
sep = ", ";
i++;
}

va_end(args);
printf("\n");
}
