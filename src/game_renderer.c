#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "game.h"
#include "grid.h"
#include "palette.h"
#include "game_renderer.h"
#include "font_renderer.h"

GameScreen game_current_screen = GameScreen_HOME;
GameButtonPosition game_play_button_position = { 0 };

void draw_crown(float pos_x, float pos_y)
{
	// Draw velvet
	al_draw_filled_ellipse(pos_x, pos_y - 3 - 60, 6, 4, COLOR_CROWN_SMALL_SPHEROID);
	al_draw_filled_ellipse(pos_x, pos_y - 3 - 30, 45, 30, COLOR_CROWN_BIG_SPHEROID);

	// Draw spines
	const float first_ball_x = pos_x - 45 - 18;
	const float first_ball_y = pos_y - 60;
	al_draw_filled_triangle(pos_x - 45, pos_y, first_ball_x, first_ball_y, pos_x - 10, pos_y, COLOR_CROWN_DIM_SPINE);
	al_draw_filled_circle(first_ball_x, first_ball_y, 6, COLOR_CROWN_SPINE_BALL);

	const float fourth_ball_x = pos_x + 45 + 16;
	const float fourth_ball_y = pos_y - 63;
	al_draw_filled_triangle(pos_x + 10, pos_y, fourth_ball_x, fourth_ball_y, pos_x + 45 + 1, pos_y, COLOR_CROWN_DIM_SPINE);
	al_draw_filled_circle(fourth_ball_x, fourth_ball_y, 6, COLOR_CROWN_SPINE_BALL);

	const float second_ball_x = pos_x - 45 + 18;
	const float second_ball_y = pos_y - 74;
	al_draw_filled_triangle(pos_x - 45 + 7, pos_y, second_ball_x, second_ball_y, pos_x + 9, pos_y, COLOR_CROWN_BRIGHT_SPINE);
	al_draw_filled_circle(second_ball_x, second_ball_y, 6, COLOR_CROWN_SPINE_BALL);

	const float third_ball_x = pos_x + 45 - 18;
	const float third_ball_y = pos_y - 73;
	al_draw_filled_triangle(pos_x - 8, pos_y, third_ball_x, third_ball_y, pos_x + 45 - 6, pos_y, COLOR_CROWN_BRIGHT_SPINE);
	al_draw_filled_circle(third_ball_x, third_ball_y, 6, COLOR_CROWN_SPINE_BALL);

	// Draw base
	al_draw_filled_rectangle(pos_x - 45, pos_y, pos_x + 45 + 1, pos_y + 14, COLOR_CROWN_BASE_INNER);

	al_draw_filled_rectangle(pos_x - 45, pos_y - 3, pos_x + 45, pos_y + 3, COLOR_CROWN_BASE_OUTER);
	al_draw_filled_circle(pos_x - 45 - 1, pos_y, 3, COLOR_CROWN_BASE_OUTER);
	al_draw_filled_circle(pos_x + 45 + 2, pos_y, 3, COLOR_CROWN_BASE_OUTER);

	al_draw_filled_rectangle(pos_x - 45, pos_y + 14 - 3, pos_x + 45, pos_y + 14 + 3, COLOR_CROWN_BASE_OUTER);
	al_draw_filled_circle(pos_x - 45 - 1, pos_y + 14, 3, COLOR_CROWN_BASE_OUTER);
	al_draw_filled_circle(pos_x + 45 + 2, pos_y + 14, 3, COLOR_CROWN_BASE_OUTER);

	// Draw reflex
	al_draw_line(pos_x - 45, pos_y - 1, pos_x - 45 + 16, pos_y - 2, COLOR_CROWN_REFLEX, 1);
	al_draw_line(pos_x - 43, pos_y, pos_x - 40 + 8, pos_y - 1, COLOR_CROWN_REFLEX, 1);

	al_draw_line(pos_x - 45, pos_y - 1, pos_x - 45 + 16, pos_y - 2, COLOR_CROWN_REFLEX, 1);
	al_draw_line(pos_x - 43, pos_y, pos_x - 40 + 8, pos_y - 1, COLOR_CROWN_REFLEX, 1);
}

void render_victory_screen()
{
	// Set background color
	al_clear_to_color(COLOR_BACKGROUND);

	// Draw crown
	float width = (float)al_get_display_width(game_display);
	float height = (float)al_get_display_height(game_display);

	float half_width = width / 2;
	float half_height = height / 2;

	draw_crown(half_width, half_height);

	ALLEGRO_FONT* font = width < 500 ? font_grid_mobile : font_grid_desktop;

	const char* message = "V i c t o r y  !";

	int text_width = al_get_text_width(font, message);
	int text_height = al_get_font_line_height(font);

	float text_start_x = half_width - text_width / 2;
	float text_start_y = half_height - text_height / 2 + 88;

	al_draw_text(font, COLOR_SQUARE_TEXT, text_start_x, text_start_y, 0, message);
}

void render_home_screen()
{
	// Set background color
	al_clear_to_color(COLOR_BACKGROUND);

	float width = (float)al_get_display_width(game_display);
	float height = (float)al_get_display_height(game_display);

	// Draw play button
	float half_width = width / 2;
	float half_height = height / 2;

	float pb_side = min(width, height) * 25 / 100;
	float pb_half_side = pb_side / 2;

	float pb_start_x = half_width - pb_half_side;
	float pb_end_x = half_width + pb_half_side;
	float pb_start_y = half_height - pb_half_side;
	float pb_end_y = half_height + pb_half_side;

	const float pb_border_radius = 6; //px

	game_play_button_position.start_x = pb_start_x;
	game_play_button_position.end_x = pb_end_x;
	game_play_button_position.start_y = pb_start_y;
	game_play_button_position.end_y = pb_end_y;

	al_draw_filled_rounded_rectangle(pb_start_x, pb_start_y, pb_end_x, pb_end_y,
		pb_border_radius, pb_border_radius, COLOR_PLAY_BUTTON_BACKGROUND);

	float icon_half_side = pb_side * 20 / 100;

	float icon_center_x = (pb_start_x + pb_end_x) / 2 + icon_half_side * 14 / 100;
	float icon_center_y = (pb_start_y + pb_end_y) / 2;

	al_draw_filled_triangle(icon_center_x - icon_half_side, icon_center_y - icon_half_side,
		icon_center_x - icon_half_side, icon_center_y + icon_half_side,
		icon_center_x + icon_half_side, icon_center_y, COLOR_PLAY_BUTTON_TRIANGLE);

	// Draw credits
	int text_height = al_get_font_line_height(font_credits);

	float text_x = 4;
	float text_y = height - (text_height + 4);

	al_draw_text(font_credits, COLOR_SQUARE_TEXT, text_x, text_y, 0, "loiury");
	text_y -= text_height;
	al_draw_text(font_credits, COLOR_SQUARE_TEXT, text_x, text_y, 0, "Wdestroier");
	text_y -= text_height;
	al_draw_text(font_credits, COLOR_SQUARE_TEXT, text_x, text_y, 0, "Credits");
}

ALLEGRO_COLOR get_square_color(int value)
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
	// Set background color
	al_clear_to_color(COLOR_BACKGROUND);

	float width = (float)al_get_display_width(game_display);
	float height = (float)al_get_display_height(game_display);

	float half_width = width / 2;
	float half_height = height / 2;

	// Draw grid background
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

	// Draw grid
	float bg_width = bg_end_x - bg_start_x;
	float bg_height = bg_end_y - bg_start_y;

	const float sq_padding = 7; //px
	const float sq_border_radius = 5; //px

	int grid_square_count = sizeof game_grid[0] / sizeof game_grid[0][0];
	assert(sizeof game_grid[0] / sizeof game_grid[0][0] == 4);
	float square_size = (bg_width - sq_padding * (grid_square_count + 1)) / grid_square_count;

	for (int r = 0; r < grid_square_count; r++)
	{
		float square_start_y = bg_start_y + sq_padding * (r + 1) + square_size * r;
		float square_end_y = square_start_y + square_size;

		for (int c = 0; c < grid_square_count; c++)
		{
			float square_start_x = bg_start_x + sq_padding * (c + 1) + square_size * c;
			float square_end_x = square_start_x + square_size;

			int square_value = game_grid[r][c];

			al_draw_filled_rounded_rectangle(square_start_x, square_start_y, square_end_x,
				square_end_y, sq_border_radius, sq_border_radius, get_square_color(square_value));

			if (square_value)
			{
				// Draw square value
				char square_value_str[21]; // long long largest width + 1
				sprintf_s(square_value_str, sizeof square_value_str, "%d", square_value);

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