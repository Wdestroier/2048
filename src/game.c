#define _CRT_SECURE_NO_WARNINGS

#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#include "game.h"
#include "logger.h"
#include "resource.h"
#include "resource_icon.h"
#include "game_mouse.h"
#include "game_renderer.h"
#include "font_renderer.h"
#include "game_keyboard.h"

#define FPS 20

char* game_executable_path;
ALLEGRO_DISPLAY* game_display;

void game_run(char* executable_path)
{
	log_info("Starting game");

	game_executable_path = executable_path;

	srand(time(0));

	if (!al_init())
	{
		log_error("Could not initialize Allegro");
		exit(-1);
	}

	al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);
	game_display = al_create_display(800, 600);

	if (!game_display)
	{
		log_error("Could not initialize the display");
		exit(-1);
	}

	al_set_window_title(game_display, "2048");

	al_install_mouse();
	al_install_keyboard();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();

	ALLEGRO_BITMAP* icon = game_get_icon();

	al_set_display_icon(game_display, icon);

	font_load_all();

	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(game_display));

	ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_start_timer(timer);

	bool running = true;

	while (running)
	{
		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);

		switch (event.type)
		{
		case ALLEGRO_EVENT_TIMER:
			render_current_screen();

			break;
		case ALLEGRO_EVENT_KEY_DOWN:
			keyboard_keypress(event.keyboard.keycode);

			break;
		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
			mouse_press(event.mouse.button, event.mouse.x, event.mouse.y);

			break;
		case ALLEGRO_EVENT_DISPLAY_RESIZE:
			al_acknowledge_resize(game_display);

			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			running = false;

			break;
		}
	}

	al_destroy_event_queue(event_queue);
	al_destroy_display(game_display);

	log_info("Closing game");
}