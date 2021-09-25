#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "game.h"
#include "game_grid.h"
#include "game_palette.h"
#include "game_renderer.h"
#include "game_font.h"

GameScreen game_current_screen = GameScreen_HOME;

void render_home_screen();
void render_ingame_screen();
void render_victory_screen();

void render_current_screen()
{
	switch (game_current_screen)
	{
	case GameScreen_HOME:
		render_home_screen();
		break;
	case GameScreen_INGAME:
		render_ingame_screen();
		break;
	case GameScreen_VICTORY:
		render_victory_screen();
		break;
	}

	al_flip_display();
}