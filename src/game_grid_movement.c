#include <stdio.h>

#include "game_grid.h"

bool grid_move_up()
{
	bool moved = false;

	for (int n = 0; n < GRID_SIDE_SQUARE_COUNT - 1; n++)
	{
		for (int c = 0; c < GRID_SIDE_SQUARE_COUNT; c++)
		{
			// Ignore the last square (GRID_SIDE_SQUARE_COUNT - 1), because the
			// next value (GRID_SIDE_SQUARE_COUNT) doesn't exist
			for (int r = 0; r < GRID_SIDE_SQUARE_COUNT - 1; r++)
			{
				int* current_square_value = &game_grid[r][c];
				int* next_square_value = &game_grid[r + 1][c];

				if (*next_square_value == 0)
				{
					continue;
				}
				else if (*next_square_value == *current_square_value)
				{
					*current_square_value += *next_square_value;
					*next_square_value = 0;

					moved = true;
				}
				else if (*current_square_value == 0)
				{
					*current_square_value = *next_square_value;
					*next_square_value = 0;

					moved = true;
				}
			}
		}
	}

	return moved;
}

bool grid_move_down()
{
	bool moved = false;

	for (int n = 0; n < GRID_SIDE_SQUARE_COUNT - 1; n++)
	{
		for (int c = 0; c < GRID_SIDE_SQUARE_COUNT; c++)
		{
			// Ignore the last square (0), because the prev value (-1) doesn't exist
			for (int r = GRID_SIDE_SQUARE_COUNT - 1; r > 0; r--)
			{
				int* current_square_value = &game_grid[r][c];
				int* prev_square_value = &game_grid[r - 1][c];

				if (*prev_square_value == 0)
				{
					continue;
				}
				else if (*prev_square_value == *current_square_value)
				{
					*current_square_value += *prev_square_value;
					*prev_square_value = 0;

					moved = true;
				}
				else if (*current_square_value == 0)
				{
					*current_square_value = *prev_square_value;
					*prev_square_value = 0;

					moved = true;
				}
			}
		}
	}

	return moved;
}

bool grid_move_left()
{
	bool moved = false;

	for (int n = 0; n < GRID_SIDE_SQUARE_COUNT - 1; n++)
	{
		for (int r = 0; r < GRID_SIDE_SQUARE_COUNT; r++)
		{
			int* current_row = game_grid[r];

			// Ignore the last square (GRID_SIDE_SQUARE_COUNT - 1), because the
			// next value (GRID_SIDE_SQUARE_COUNT) doesn't exist
			for (int c = 0; c < GRID_SIDE_SQUARE_COUNT - 1; c++)
			{
				int* current_square_value = &current_row[c];
				int* next_square_value = &current_row[c + 1];

				if (*next_square_value == 0)
				{
					continue;
				}
				else if (*next_square_value == *current_square_value)
				{
					*current_square_value += *next_square_value;
					*next_square_value = 0;

					moved = true;
				}
				else if (*current_square_value == 0)
				{
					*current_square_value = *next_square_value;
					*next_square_value = 0;

					moved = true;
				}
			}
		}
	}

	return moved;
}

bool grid_move_right()
{
	bool moved = false;

	for (int n = 0; n < GRID_SIDE_SQUARE_COUNT - 1; n++)
	{
		for (int r = 0; r < GRID_SIDE_SQUARE_COUNT; r++)
		{
			int* current_row = game_grid[r];

			// Ignore the last square (0), because the previous value (-1) doesn't exist
			for (int c = GRID_SIDE_SQUARE_COUNT - 1; c > 0; c--)
			{
				int* current_square_value = &current_row[c];
				int* prev_square_value = &current_row[c - 1];

				if (*prev_square_value == 0)
				{
					continue;
				}
				else if (*prev_square_value == *current_square_value)
				{
					*current_square_value += *prev_square_value;
					*prev_square_value = 0;

					moved = true;
				}
				else if (*current_square_value == 0)
				{
					*current_square_value = *prev_square_value;
					*prev_square_value = 0;

					moved = true;
				}
			}
		}
	}

	return moved;
}