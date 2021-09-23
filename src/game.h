#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

extern char* game_executable_path;

//TODO If the project has errors related to allegro_font.h, then comment these lines in allegro_font.h:
//ALLEGRO_FONT_PRINTFUNC(void, al_draw_textf, (const ALLEGRO_FONT *font, ALLEGRO_COLOR color, float x, float y, int flags, char const *format, ...), 6, 7);
//ALLEGRO_FONT_PRINTFUNC(void, al_draw_justified_textf, (const ALLEGRO_FONT *font, ALLEGRO_COLOR color, float x1, float x2, float y, float diff, int flags, char const *format, ...), 8, 9);

extern ALLEGRO_DISPLAY* game_display;

void game_run(char* executable_path);