#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>

#include "game.h"
#include "game_font.h"
#include "game_palette.h"
#include "game_renderer.h"

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