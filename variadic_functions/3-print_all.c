#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
*print_all - Prints anything based on format specifiers
*@format: A string of format specifiers
*
*Description: Supported specifiers:
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
char *sep = "";
char *str;

va_start(args, format);

while (format && format[i])
{
switch (format[i])
{
case 'c':
printf("%s%c", sep, va_arg(args, int));
sep = ", ";
break;
case 'i':
printf("%s%d", sep, va_arg(args, int));
sep = ", ";
break;
case 'f':
printf("%s%f", sep, va_arg(args, double));
sep = ", ";
break;
case 's':
str = va_arg(args, char *);
if (str == NULL)
str = "(nil)";
printf("%s%s", sep, str);
sep = ", ";
break;
default:
break;
}
i++;
}

va_end(args);
printf("\n");
}
