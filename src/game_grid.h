#pragma once

#include <stdbool.h>

typedef int GameGrid[4][4];

extern GameGrid game_grid;

int* grid_find_free_square();
void grid_reset();
bool grid_spawn_square(int value);
bool grid_contains_square(int value);

bool grid_move_up();
bool grid_move_down();
bool grid_move_left();
bool grid_move_right();