#include <stdbool.h>

#include <allegro5/allegro.h>

#include "game_logger.h"
#include "game_keyboard.h"
#include "game_renderer.h"
#include "game_grid.h"

void keyboard_keypress(int keycode)
{
	//TODO Only process UP, DOWN, LEFT and RIGHT keys if the player in ingame.

	bool moved = false;

	switch (keycode)
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
	case ALLEGRO_KEY_F5:
		grid_reset();
		game_current_screen = GameScreen_INGAME;
		break;
	}

	if (moved)
	{
		if (grid_contains_square(2048))
		{
			game_current_screen = GameScreen_VICTORY;
			log_info("Player has won the game");
		}
		else
		{
			int square_value = (rand() % 5 == 4) ? 4 : 2;
			bool spawned_square = grid_spawn_square(square_value);

			if (!spawned_square) // && grid is full
			{
				
				// the player lost
			}
		}
	}
}