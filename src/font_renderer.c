#define _CRT_SECURE_NO_WARNINGS

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "game.h"
#include "logger.h"
#include "resource.h"
#include "font_renderer.h"
#include "game_font.h"

bool fonts_initialized = false;

char* font_absolute_path = 0;

ALLEGRO_FONT* font_grid_mobile;
ALLEGRO_FONT* font_grid_desktop;
ALLEGRO_FONT* font_credits;

void font_load_all()
{
	int width = al_get_display_width(game_display);

	if (fonts_initialized)
	{
		al_destroy_font(font_grid_mobile);
		al_destroy_font(font_grid_desktop);
	}
	else
	{
		font_absolute_path = resource_extract("HelveticaNeueInterface.ttf",
			font_helvetica_neue_interface, sizeof font_helvetica_neue_interface);

		font_credits = al_load_font(font_absolute_path, width * 2 / 100, 0);
	}

	font_grid_mobile = al_load_font(font_absolute_path, width * 3 / 100, 0);
	font_grid_desktop = al_load_font(font_absolute_path, width * 5 / 100, 0);

	fonts_initialized = true;
}