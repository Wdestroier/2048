#define _CRT_SECURE_NO_WARNINGS

#include <math.h>
#include <stdio.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>

#include "game.h"
#include "game_grid.h"
#include "game_font.h"
#include "game_palette.h"
#include "game_renderer.h"

ALLEGRO_COLOR grid_get_square_color(int value)
{
	ALLEGRO_COLOR color;

	int exponent = (int)round(log(value) / log(2));

	switch (exponent)
	{
	case 1: // 2
		color = COLOR_SQUARE_VALUE_1;
		break;
	case 2: // 4
		color = COLOR_SQUARE_VALUE_2;
		break;
	case 3: // 8
		color = COLOR_SQUARE_VALUE_3;
		break;
	case 4: // 16
		color = COLOR_SQUARE_VALUE_4;
		break;
	case 5: // 32
		color = COLOR_SQUARE_VALUE_5;
		break;
	case 6: // 64
		color = COLOR_SQUARE_VALUE_6;
		break;
	case 7: // 128
		color = COLOR_SQUARE_VALUE_7;
		break;
	case 8: // 256
		color = COLOR_SQUARE_VALUE_8;
		break;
	case 9: // 512
		color = COLOR_SQUARE_VALUE_9;
		break;
	case 10: // 1024
		color = COLOR_SQUARE_VALUE_10;
		break;
	case 11: // 2048
		color = COLOR_SQUARE_VALUE_11;
		break;
	default: // 0 or any number beyond 2048
		color = COLOR_SQUARE_VALUE_0;
		break;
	}

	return color;
}

void render_ingame_screen()
{
	// Set the background color
	al_clear_to_color(COLOR_BACKGROUND);

	float width = (float)al_get_display_width(game_display);
	float height = (float)al_get_display_height(game_display);

	float half_width = width / 2;
	float half_height = height / 2;

	// Draw the grid background
	float bg_side = min(width, height) * 80 / 100;
	float bg_half_side = bg_side / 2;

	const float bg_padding = 8; //px

	float bg_start_x = half_width - bg_half_side + bg_padding;
	float bg_start_y = half_height - bg_half_side + bg_padding;
	float bg_end_x = half_width + bg_half_side - bg_padding;
	float bg_end_y = half_height + bg_half_side - bg_padding;

	const float bg_border_radius = 10; //px

	al_draw_filled_rounded_rectangle(bg_start_x, bg_start_y, bg_end_x, bg_end_y,
		bg_border_radius, bg_border_radius, COLOR_GRID_BACKGROUND);

	// Draw the grid
	float bg_width = bg_end_x - bg_start_x;
	float bg_height = bg_end_y - bg_start_y;

	const float sq_padding = 7; //px
	const float sq_border_radius = 5; //px

	float square_size = (bg_width - sq_padding * (GRID_SIDE_SQUARE_COUNT + 1)) / GRID_SIDE_SQUARE_COUNT;

	for (int r = 0; r < GRID_SIDE_SQUARE_COUNT; r++)
	{
		float square_start_y = bg_start_y + sq_padding * (r + 1) + square_size * r;
		float square_end_y = square_start_y + square_size;

		for (int c = 0; c < GRID_SIDE_SQUARE_COUNT; c++)
		{
			float square_start_x = bg_start_x + sq_padding * (c + 1) + square_size * c;
			float square_end_x = square_start_x + square_size;

			int square_value = game_grid[r][c];

			al_draw_filled_rounded_rectangle(square_start_x, square_start_y, square_end_x,
				square_end_y, sq_border_radius, sq_border_radius, grid_get_square_color(square_value));

			if (square_value)
			{
				// Draw the square value
				char square_value_str[21]; // long long largest width + 1
				sprintf(square_value_str, "%d", square_value);

				ALLEGRO_FONT* font_grid = width < 500 ? font_grid_mobile : font_grid_desktop;

				int text_width = al_get_text_width(font_grid, square_value_str);
				int text_height = al_get_font_line_height(font_grid);

				float text_start_x = square_start_x + square_size / 2 - text_width / 2;
				float text_start_y = square_start_y + square_size / 2 - text_height / 2;

				al_draw_text(font_grid, COLOR_SQUARE_TEXT, text_start_x, text_start_y, 0,
					square_value_str);
			}
		}
	}
}