#include <stdbool.h>

#include <allegro5/allegro.h>

#include "game_logger.h"
#include "game_keyboard.h"
#include "game_renderer.h"
#include "game_grid.h"

void keyboard_key_down_ingame(key_code)
{
	bool moved = false;

	switch (key_code)
	{
	case ALLEGRO_KEY_UP:
		moved = grid_move_up();
		break;
	case ALLEGRO_KEY_DOWN:
		moved = grid_move_down();
		break;
	case ALLEGRO_KEY_LEFT:
		moved = grid_move_left();
		break;
	case ALLEGRO_KEY_RIGHT:
		moved = grid_move_right();
		break;
	}

	if (moved)
	{
		if (grid_contains_square(2048))
		{
			log_info("Player has won the game");
			game_current_screen = GameScreen_VICTORY;
		}
		else
		{
			// Spawns a square if the grid is not full
			int square_value = (rand() % 5 == 4) ? 4 : 2;
			grid_spawn_square(square_value);
		}
	}
	else
	{
		if (grid_is_full())
		{
			log_info("Player has lost the game");
			grid_reset();
			//TODO Create a defeat screen and show it?
		}
	}
}

void keyboard_key_down(int key_code)
{
	if (game_current_screen == GameScreen_INGAME)
	{
		keyboard_key_down_ingame(key_code);
	}

	if (key_code == ALLEGRO_KEY_F5)
	{
		grid_reset();
		game_current_screen = GameScreen_INGAME;
	}
}