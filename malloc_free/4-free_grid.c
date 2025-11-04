#include <stdlib.h>

/**
* free_grid - frees a 2D grid created by alloc_grid
* @grid: pointer to the grid
* @height: number of rows in the grid
*
* Return: Nothing
*/
void free_grid(int **grid, int height)
{
int i;

for (i = 0; i < height; i++)
free(grid[i]);

free(grid);
}
