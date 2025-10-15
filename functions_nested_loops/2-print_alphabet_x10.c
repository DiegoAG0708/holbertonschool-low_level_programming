#include "main.h"

/**
* print_alphabet_x10 - prints the alphabet 10 times
*/
void print_alphabet_x10(void)
{
int line, letter;

for (line = 0; line < 10; line++)
{
for (letter = 'a'; letter <= 'z'; letter++)
_putchar(letter);
_putchar('\n');
}
}
