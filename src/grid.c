#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "grid.h"

#define GRID_SIDE_SIZE (sizeof(game_grid)/sizeof(game_grid[0]))

GameGrid game_grid = { 0 };

int* grid_find_free_square()
{
	int valid_square_count = 0;

	int* valid_squares[GRID_SIDE_SIZE * GRID_SIDE_SIZE];

	for (int r = 0; r < GRID_SIDE_SIZE; r++)
	{
		for (int c = 0; c < GRID_SIDE_SIZE; c++)
		{
			if (game_grid[r][c] == 0)
			{
				valid_squares[valid_square_count] = &game_grid[r][c];

				valid_square_count++;
			}
		}
	}

	int* square = 0;

	if (valid_square_count != 0)
	{
		// Generate a random number between 0 and valid_square_count - 1
		int square_index = rand() % valid_square_count;

		square = valid_squares[square_index];
	}

	return square;
}

bool grid_spawn_square(int value)
{
	bool spawned = false;

	int* free_square = grid_find_free_square();
	
	if (free_square)
	{
		*free_square = value;
		spawned = true;
	}
	
	return spawned;
}

void grid_reset()
{
	memset(game_grid, 0, sizeof game_grid);

	grid_spawn_square(2);
	grid_spawn_square(2);
}

bool grid_contains_square(int value)
{
	bool contains_square = false;

	int grid_square_count = sizeof game_grid[0] / sizeof game_grid[0][0];

	for (int r = 0; r < grid_square_count; r++)
	{
		for (int c = 0; c < grid_square_count; c++)
		{
			if (game_grid[r][c] == value)
			{
				contains_square = true;
				goto iteration_over;
			}
		}
	}
	
	iteration_over:
	return contains_square;
}