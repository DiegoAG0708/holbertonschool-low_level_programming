#include "main.h"

/**
* _sqrt_helper - recursive helper to find square root
* @n: the number to find the square root of
* @i: the current guess
*
* Return: natural square root or -1 if none
*/
int _sqrt_helper(int n, int i)
{
if (i * i > n)
return (-1);
if (i * i == n)
return (i);
return (_sqrt_helper(n, i + 1));
}

/**
* _sqrt_recursion - returns the natural square root of a number
* @n: the number to compute
*
* Return: natural square root or -1 if not a perfect square
*/
int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);
return (_sqrt_helper(n, 0));
}
