#include <stdio.h>

#include "game_grid.h"

bool grid_move_up()
{
	bool moved_any_square = false;

	// Move all squares up
	for (int i = 0; i < GRID_SIDE_SQUARE_COUNT - 1; i++)
	{
		for (int r = 0; r < GRID_SIDE_SQUARE_COUNT; r++)
		{
			for (int c = GRID_SIDE_SQUARE_COUNT - 1; c > 0; c--)
			{
				int current_square_value = game_grid[c][r];
				int previous_square_value = game_grid[c - 1][r];

				if (previous_square_value == 0 && current_square_value != 0)
				{
					game_grid[c - 1][r] = game_grid[c][r];
					game_grid[c][r] = 0;

					moved_any_square = true;
				}
			}
		}
	}

	// Merge equal squares
	for (int r = 0; r < GRID_SIDE_SQUARE_COUNT; r++)
	{
		for (int c = GRID_SIDE_SQUARE_COUNT - 1; c > 0; c--)
		{
			int current_square_value = game_grid[c][r];
			int previous_square_value = game_grid[c - 1][r];

			if (previous_square_value == current_square_value)
			{
				game_grid[c][r] = 0;
				game_grid[c - 1][r] += current_square_value;

				moved_any_square = true;
			}
		}
	}

	// Move all squares up
	for (int i = 0; i < GRID_SIDE_SQUARE_COUNT - 1; i++)
	{
		for (int r = 0; r < GRID_SIDE_SQUARE_COUNT; r++)
		{
			for (int c = GRID_SIDE_SQUARE_COUNT - 1; c > 0; c--)
			{
				int current_square_value = game_grid[c][r];
				int previous_square_value = game_grid[c - 1][r];

				if (previous_square_value == 0 && current_square_value != 0)
				{
					game_grid[c - 1][r] = game_grid[c][r];
					game_grid[c][r] = 0;

					moved_any_square = true;
				}
			}
		}
	}

	return moved_any_square;
}

bool grid_move_down()
{
	bool moved_any_square = false;

	// Move all squares down
	for (int i = 0; i < GRID_SIDE_SQUARE_COUNT - 1; i++)
	{
		for (int r = 0; r < GRID_SIDE_SQUARE_COUNT; r++)
		{
			for (int c = 0; c < GRID_SIDE_SQUARE_COUNT - 1; c++)
			{
				int current_square_value = game_grid[c][r];
				int next_square_value = game_grid[c + 1][r];

				if (next_square_value == 0 && current_square_value != 0)
				{
					game_grid[c + 1][r] = game_grid[c][r];
					game_grid[c][r] = 0;

					moved_any_square = true;
				}
			}
		}
	}

	// Merge equal squares
	for (int r = 0; r < GRID_SIDE_SQUARE_COUNT; r++)
	{
		for (int c = 0; c < GRID_SIDE_SQUARE_COUNT - 1; c++)
		{
			int current_square_value = game_grid[c][r];
			int next_square_value = game_grid[c + 1][r];

			if (next_square_value == current_square_value && current_square_value != 0)
			{
				game_grid[c][r] = 0;
				game_grid[c + 1][r] += current_square_value;

				moved_any_square = true;
				//printf("BBB [%d, %d] [%d, %d]\n", c, r, c + 1, r);
			}
		}
	}

	// Move all squares down
	for (int i = 0; i < GRID_SIDE_SQUARE_COUNT - 1; i++)
	{
		for (int r = 0; r < GRID_SIDE_SQUARE_COUNT; r++)
		{
			for (int c = 0; c < GRID_SIDE_SQUARE_COUNT - 1; c++)
			{
				int current_square_value = game_grid[c][r];
				int next_square_value = game_grid[c + 1][r];

				if (next_square_value == 0 && current_square_value != 0)
				{
					game_grid[c + 1][r] = game_grid[c][r];
					game_grid[c][r] = 0;

					moved_any_square = true;
				}
			}
		}
	}

	return moved_any_square;
}

bool grid_move_left()
{
	bool moved_any_square = false;

	// Move all squares to the left
	for (int i = 0; i < GRID_SIDE_SQUARE_COUNT - 1; i++)
	{
		for (int r = 0; r < GRID_SIDE_SQUARE_COUNT; r++)
		{
			for (int c = GRID_SIDE_SQUARE_COUNT - 1; c > 0; c--)
			{
				int current_square_value = game_grid[r][c];
				int previous_square_value = game_grid[r][c - 1];

				if (previous_square_value == 0 && current_square_value != 0)
				{
					game_grid[r][c - 1] = game_grid[r][c];
					game_grid[r][c] = 0;

					moved_any_square = true;
				}
			}
		}
	}

	// Merge equal squares
	for (int r = 0; r < GRID_SIDE_SQUARE_COUNT; r++)
	{
		for (int c = GRID_SIDE_SQUARE_COUNT - 1; c > 0; c--)
		{
			int current_square_value = game_grid[r][c];
			int previous_square_value = game_grid[r][c - 1];

			if (previous_square_value == current_square_value)
			{
				game_grid[r][c] = 0;
				game_grid[r][c - 1] += current_square_value;

				moved_any_square = true;
			}
		}
	}

	// Move all squares to the left
	for (int i = 0; i < GRID_SIDE_SQUARE_COUNT - 1; i++)
	{
		for (int r = 0; r < GRID_SIDE_SQUARE_COUNT; r++)
		{
			for (int c = GRID_SIDE_SQUARE_COUNT - 1; c > 0; c--)
			{
				int current_square_value = game_grid[r][c];
				int previous_square_value = game_grid[r][c - 1];

				if (previous_square_value == 0 && current_square_value != 0)
				{
					game_grid[r][c - 1] = game_grid[r][c];
					game_grid[r][c] = 0;

					moved_any_square = true;
				}
			}
		}
	}

	return moved_any_square;
}

bool grid_move_right()
{
	bool moved_any_square = false;

	// Move all squares to the right
	for (int i = 0; i < GRID_SIDE_SQUARE_COUNT - 1; i++)
	{
		for (int r = 0; r < GRID_SIDE_SQUARE_COUNT; r++)
		{
			for (int c = 0; c < GRID_SIDE_SQUARE_COUNT - 1; c++)
			{
				int current_square_value = game_grid[r][c];
				int next_square_value = game_grid[r][c + 1];

				if (current_square_value != 0 && next_square_value == 0 && current_square_value != 0)
				{
					game_grid[r][c + 1] = game_grid[r][c];
					game_grid[r][c] = 0;

					moved_any_square = true;
				}
			}
		}
	}

	// Merge equal squares
	for (int r = 0; r < GRID_SIDE_SQUARE_COUNT; r++)
	{
		for (int c = 0; c < GRID_SIDE_SQUARE_COUNT - 1; c++)
		{
			int current_square_value = game_grid[r][c];

			if (current_square_value != 0)
			{
				int next_square_value = game_grid[r][c + 1];

				if (next_square_value != current_square_value)
					continue;

				game_grid[r][c] = 0;
				game_grid[r][c + 1] += current_square_value;

				moved_any_square = true;
			}
		}
	}

	// Move all squares to the right
	for (int i = 0; i < GRID_SIDE_SQUARE_COUNT - 1; i++)
	{
		for (int r = 0; r < GRID_SIDE_SQUARE_COUNT; r++)
		{
			for (int c = 0; c < GRID_SIDE_SQUARE_COUNT - 1; c++)
			{
				int current_square_value = game_grid[r][c];
				int next_square_value = game_grid[r][c + 1];

				if (next_square_value == 0 && current_square_value != 0)
				{
					game_grid[r][c + 1] = game_grid[r][c];
					game_grid[r][c] = 0;

					moved_any_square = true;
				}
			}
		}
	}

	return moved_any_square;
}