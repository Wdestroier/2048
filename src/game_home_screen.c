#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>

#include "game.h"
#include "game_font.h"
#include "game_palette.h"
#include "game_renderer.h"

GameButtonPosition game_play_button_position = { 0 };

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