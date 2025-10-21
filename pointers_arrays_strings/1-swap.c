#include "main.h"

/**
* swap_int - does magic
* @a: pointer first
* @b: pointer 2
*
* Return:
*/
void swap_int(int *a, int *b)
{
int temp;

temp = *a;
*a = *b;
*b = temp;
}
