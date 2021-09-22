#pragma once

typedef enum {
	GameScreen_HOME,
	GameScreen_INGAME,
	GameScreen_VICTORY,
} GameScreen;

typedef struct {
	float start_x;
	float end_x;
	float start_y;
	float end_y;
} GameButtonPosition;

extern GameScreen game_current_screen;

extern GameButtonPosition game_play_button_position;

void render_current_screen();