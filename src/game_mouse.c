#include <stdio.h>

#include "game_logger.h"
#include "game_mouse.h"
#include "game_renderer.h"
#include "game_grid.h"

void mouse_press(int button, int x, int y)
{
	// Left click
	if (button == 1)
	{
		switch (game_current_screen)
		{
		case GameScreen_HOME:
			if (x >= game_play_button_position.start_x && x <= game_play_button_position.end_x
				&& y >= game_play_button_position.start_y && y <= game_play_button_position.end_y)
			{
				grid_reset();
				game_current_screen = GameScreen_INGAME;
				log_info("Grid reset");
			}

			break;
		}
	}
}