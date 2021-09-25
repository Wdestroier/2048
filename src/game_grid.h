#pragma once

#include <stdbool.h>

#define GRID_SIDE_SQUARE_COUNT 4

typedef int GameGrid[GRID_SIDE_SQUARE_COUNT][GRID_SIDE_SQUARE_COUNT];

extern GameGrid game_grid;

bool grid_spawn_square(int value);
bool grid_contains_square(int value);
bool grid_is_full();
void grid_reset();

bool grid_move_up();
bool grid_move_down();
bool grid_move_left();
bool grid_move_right();