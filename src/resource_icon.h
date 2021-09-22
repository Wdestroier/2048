#pragma once

#include "game.h"

static ALLEGRO_BITMAP* game_get_icon()
{
	ALLEGRO_BITMAP* icon = al_create_bitmap(16, 16);

	al_set_target_bitmap(icon);

	al_put_pixel(0, 0, al_map_rgb(214, 204, 195));
	al_put_pixel(0, 1, al_map_rgb(218, 207, 187));
	al_put_pixel(0, 2, al_map_rgb(217, 206, 188));
	al_put_pixel(0, 3, al_map_rgb(216, 205, 187));
	al_put_pixel(0, 4, al_map_rgb(215, 204, 198));
	al_put_pixel(0, 5, al_map_rgb(216, 208, 189));
	al_put_pixel(0, 6, al_map_rgb(217, 205, 189));
	al_put_pixel(0, 7, al_map_rgb(219, 206, 189));
	al_put_pixel(0, 8, al_map_rgb(220, 202, 190));
	al_put_pixel(0, 9, al_map_rgb(222, 209, 193));
	al_put_pixel(0, 10, al_map_rgb(217, 209, 188));
	al_put_pixel(0, 11, al_map_rgb(213, 199, 198));
	al_put_pixel(0, 12, al_map_rgb(220, 208, 182));
	al_put_pixel(0, 13, al_map_rgb(218, 202, 187));
	al_put_pixel(0, 14, al_map_rgb(219, 208, 190));
	al_put_pixel(0, 15, al_map_rgb(212, 203, 194));
	al_put_pixel(1, 0, al_map_rgb(217, 207, 197));
	al_put_pixel(1, 1, al_map_rgb(232, 221, 199));
	al_put_pixel(1, 2, al_map_rgb(236, 223, 204));
	al_put_pixel(1, 3, al_map_rgb(234, 223, 203));
	al_put_pixel(1, 4, al_map_rgb(217, 207, 198));
	al_put_pixel(1, 5, al_map_rgb(230, 222, 201));
	al_put_pixel(1, 6, al_map_rgb(236, 225, 207));
	al_put_pixel(1, 7, al_map_rgb(235, 222, 203));
	al_put_pixel(1, 8, al_map_rgb(221, 205, 192));
	al_put_pixel(1, 9, al_map_rgb(232, 219, 203));
	al_put_pixel(1, 10, al_map_rgb(231, 223, 200));
	al_put_pixel(1, 11, al_map_rgb(217, 204, 198));
	al_put_pixel(1, 12, al_map_rgb(235, 223, 197));
	al_put_pixel(1, 13, al_map_rgb(237, 221, 205));
	al_put_pixel(1, 14, al_map_rgb(234, 223, 203));
	al_put_pixel(1, 15, al_map_rgb(216, 206, 196));
	al_put_pixel(2, 0, al_map_rgb(217, 205, 191));
	al_put_pixel(2, 1, al_map_rgb(236, 224, 198));
	al_put_pixel(2, 2, al_map_rgb(222, 210, 186));
	al_put_pixel(2, 3, al_map_rgb(233, 221, 197));
	al_put_pixel(2, 4, al_map_rgb(219, 207, 193));
	al_put_pixel(2, 5, al_map_rgb(233, 223, 198));
	al_put_pixel(2, 6, al_map_rgb(221, 209, 187));
	al_put_pixel(2, 7, al_map_rgb(237, 222, 199));
	al_put_pixel(2, 8, al_map_rgb(214, 205, 188));
	al_put_pixel(2, 9, al_map_rgb(217, 209, 188));
	al_put_pixel(2, 10, al_map_rgb(235, 225, 200));
	al_put_pixel(2, 11, al_map_rgb(217, 207, 195));
	al_put_pixel(2, 12, al_map_rgb(236, 224, 200));
	al_put_pixel(2, 13, al_map_rgb(223, 212, 192));
	al_put_pixel(2, 14, al_map_rgb(233, 223, 198));
	al_put_pixel(2, 15, al_map_rgb(216, 204, 188));
	al_put_pixel(3, 0, al_map_rgb(215, 203, 189));
	al_put_pixel(3, 1, al_map_rgb(238, 226, 200));
	al_put_pixel(3, 2, al_map_rgb(239, 224, 201));
	al_put_pixel(3, 3, al_map_rgb(236, 224, 200));
	al_put_pixel(3, 4, al_map_rgb(215, 203, 189));
	al_put_pixel(3, 5, al_map_rgb(237, 227, 202));
	al_put_pixel(3, 6, al_map_rgb(237, 225, 203));
	al_put_pixel(3, 7, al_map_rgb(238, 223, 200));
	al_put_pixel(3, 8, al_map_rgb(216, 207, 192));
	al_put_pixel(3, 9, al_map_rgb(234, 223, 205));
	al_put_pixel(3, 10, al_map_rgb(237, 227, 202));
	al_put_pixel(3, 11, al_map_rgb(213, 206, 190));
	al_put_pixel(3, 12, al_map_rgb(246, 217, 187));
	al_put_pixel(3, 13, al_map_rgb(245, 221, 193));
	al_put_pixel(3, 14, al_map_rgb(244, 221, 187));
	al_put_pixel(3, 15, al_map_rgb(229, 203, 178));
	al_put_pixel(4, 0, al_map_rgb(217, 207, 197));
	al_put_pixel(4, 1, al_map_rgb(215, 204, 184));
	al_put_pixel(4, 2, al_map_rgb(216, 205, 187));
	al_put_pixel(4, 3, al_map_rgb(218, 207, 189));
	al_put_pixel(4, 4, al_map_rgb(215, 205, 196));
	al_put_pixel(4, 5, al_map_rgb(213, 206, 187));
	al_put_pixel(4, 6, al_map_rgb(215, 207, 188));
	al_put_pixel(4, 7, al_map_rgb(216, 205, 185));
	al_put_pixel(4, 8, al_map_rgb(219, 204, 197));
	al_put_pixel(4, 9, al_map_rgb(217, 205, 191));
	al_put_pixel(4, 10, al_map_rgb(216, 204, 180));
	al_put_pixel(4, 11, al_map_rgb(212, 210, 197));
	al_put_pixel(4, 12, al_map_rgb(237, 178, 134));
	al_put_pixel(4, 13, al_map_rgb(229, 180, 137));
	al_put_pixel(4, 14, al_map_rgb(225, 177, 128));
	al_put_pixel(4, 15, al_map_rgb(228, 181, 137));
	al_put_pixel(5, 0, al_map_rgb(217, 204, 195));
	al_put_pixel(5, 1, al_map_rgb(236, 223, 204));
	al_put_pixel(5, 2, al_map_rgb(235, 222, 205));
	al_put_pixel(5, 3, al_map_rgb(235, 222, 205));
	al_put_pixel(5, 4, al_map_rgb(217, 204, 196));
	al_put_pixel(5, 5, al_map_rgb(232, 224, 205));
	al_put_pixel(5, 6, al_map_rgb(234, 223, 205));
	al_put_pixel(5, 7, al_map_rgb(236, 223, 204));
	al_put_pixel(5, 8, al_map_rgb(217, 202, 195));
	al_put_pixel(5, 9, al_map_rgb(234, 220, 207));
	al_put_pixel(5, 10, al_map_rgb(238, 226, 204));
	al_put_pixel(5, 11, al_map_rgb(209, 207, 194));
	al_put_pixel(5, 12, al_map_rgb(245, 172, 121));
	al_put_pixel(5, 13, al_map_rgb(229, 167, 118));
	al_put_pixel(5, 14, al_map_rgb(231, 169, 112));
	al_put_pixel(5, 15, al_map_rgb(237, 175, 124));
	al_put_pixel(6, 0, al_map_rgb(215, 203, 189));
	al_put_pixel(6, 1, al_map_rgb(239, 227, 203));
	al_put_pixel(6, 2, al_map_rgb(221, 209, 187));
	al_put_pixel(6, 3, al_map_rgb(234, 222, 200));
	al_put_pixel(6, 4, al_map_rgb(218, 206, 194));
	al_put_pixel(6, 5, al_map_rgb(235, 224, 202));
	al_put_pixel(6, 6, al_map_rgb(219, 207, 185));
	al_put_pixel(6, 7, al_map_rgb(238, 223, 200));
	al_put_pixel(6, 8, al_map_rgb(218, 205, 196));
	al_put_pixel(6, 9, al_map_rgb(219, 207, 191));
	al_put_pixel(6, 10, al_map_rgb(236, 222, 196));
	al_put_pixel(6, 11, al_map_rgb(210, 202, 189));
	al_put_pixel(6, 12, al_map_rgb(248, 177, 125));
	al_put_pixel(6, 13, al_map_rgb(227, 164, 113));
	al_put_pixel(6, 14, al_map_rgb(237, 172, 116));
	al_put_pixel(6, 15, al_map_rgb(241, 173, 124));
	al_put_pixel(7, 0, al_map_rgb(229, 203, 180));
	al_put_pixel(7, 1, al_map_rgb(246, 220, 187));
	al_put_pixel(7, 2, al_map_rgb(246, 219, 189));
	al_put_pixel(7, 3, al_map_rgb(248, 221, 191));
	al_put_pixel(7, 4, al_map_rgb(226, 199, 178));
	al_put_pixel(7, 5, al_map_rgb(246, 221, 190));
	al_put_pixel(7, 6, al_map_rgb(247, 222, 191));
	al_put_pixel(7, 7, al_map_rgb(247, 218, 186));
	al_put_pixel(7, 8, al_map_rgb(232, 199, 182));
	al_put_pixel(7, 9, al_map_rgb(250, 215, 195));
	al_put_pixel(7, 10, al_map_rgb(255, 220, 194));
	al_put_pixel(7, 11, al_map_rgb(233, 200, 183));
	al_put_pixel(7, 12, al_map_rgb(231, 177, 131));
	al_put_pixel(7, 13, al_map_rgb(229, 181, 135));
	al_put_pixel(7, 14, al_map_rgb(230, 178, 130));
	al_put_pixel(7, 15, al_map_rgb(232, 177, 138));
	al_put_pixel(8, 0, al_map_rgb(227, 179, 139));
	al_put_pixel(8, 1, al_map_rgb(226, 179, 127));
	al_put_pixel(8, 2, al_map_rgb(228, 180, 132));
	al_put_pixel(8, 3, al_map_rgb(227, 179, 131));
	al_put_pixel(8, 4, al_map_rgb(227, 179, 141));
	al_put_pixel(8, 5, al_map_rgb(227, 181, 131));
	al_put_pixel(8, 6, al_map_rgb(228, 180, 132));
	al_put_pixel(8, 7, al_map_rgb(229, 179, 130));
	al_put_pixel(8, 8, al_map_rgb(217, 141, 117));
	al_put_pixel(8, 9, al_map_rgb(219, 135, 111));
	al_put_pixel(8, 10, al_map_rgb(222, 138, 110));
	al_put_pixel(8, 11, al_map_rgb(215, 138, 112));
	al_put_pixel(8, 12, al_map_rgb(252, 225, 196));
	al_put_pixel(8, 13, al_map_rgb(241, 221, 186));
	al_put_pixel(8, 14, al_map_rgb(242, 222, 185));
	al_put_pixel(8, 15, al_map_rgb(231, 203, 179));
	al_put_pixel(9, 0, al_map_rgb(237, 175, 128));
	al_put_pixel(9, 1, al_map_rgb(236, 174, 115));
	al_put_pixel(9, 2, al_map_rgb(233, 170, 116));
	al_put_pixel(9, 3, al_map_rgb(238, 177, 122));
	al_put_pixel(9, 4, al_map_rgb(235, 174, 129));
	al_put_pixel(9, 5, al_map_rgb(235, 176, 118));
	al_put_pixel(9, 6, al_map_rgb(230, 169, 114));
	al_put_pixel(9, 7, al_map_rgb(239, 177, 120));
	al_put_pixel(9, 8, al_map_rgb(234, 133, 105));
	al_put_pixel(9, 9, al_map_rgb(230, 122, 96));
	al_put_pixel(9, 10, al_map_rgb(235, 127, 99));
	al_put_pixel(9, 11, al_map_rgb(234, 130, 103));
	al_put_pixel(9, 12, al_map_rgb(236, 223, 204));
	al_put_pixel(9, 13, al_map_rgb(217, 210, 182));
	al_put_pixel(9, 14, al_map_rgb(236, 229, 201));
	al_put_pixel(9, 15, al_map_rgb(215, 201, 190));
	al_put_pixel(10, 0, al_map_rgb(239, 176, 132));
	al_put_pixel(10, 1, al_map_rgb(228, 166, 109));
	al_put_pixel(10, 2, al_map_rgb(227, 164, 111));
	al_put_pixel(10, 3, al_map_rgb(241, 178, 125));
	al_put_pixel(10, 4, al_map_rgb(235, 172, 129));
	al_put_pixel(10, 5, al_map_rgb(236, 175, 120));
	al_put_pixel(10, 6, al_map_rgb(232, 171, 117));
	al_put_pixel(10, 7, al_map_rgb(241, 176, 122));
	al_put_pixel(10, 8, al_map_rgb(233, 132, 102));
	al_put_pixel(10, 9, al_map_rgb(236, 126, 101));
	al_put_pixel(10, 10, al_map_rgb(227, 119, 93));
	al_put_pixel(10, 11, al_map_rgb(241, 132, 109));
	al_put_pixel(10, 12, al_map_rgb(234, 222, 206));
	al_put_pixel(10, 13, al_map_rgb(230, 222, 199));
	al_put_pixel(10, 14, al_map_rgb(233, 225, 204));
	al_put_pixel(10, 15, al_map_rgb(220, 203, 196));
	al_put_pixel(11, 0, al_map_rgb(229, 177, 140));
	al_put_pixel(11, 1, al_map_rgb(233, 181, 133));
	al_put_pixel(11, 2, al_map_rgb(229, 176, 132));
	al_put_pixel(11, 3, al_map_rgb(230, 179, 134));
	al_put_pixel(11, 4, al_map_rgb(227, 177, 142));
	al_put_pixel(11, 5, al_map_rgb(230, 182, 134));
	al_put_pixel(11, 6, al_map_rgb(225, 174, 129));
	al_put_pixel(11, 7, al_map_rgb(232, 180, 133));
	al_put_pixel(11, 8, al_map_rgb(222, 140, 116));
	al_put_pixel(11, 9, al_map_rgb(221, 135, 112));
	al_put_pixel(11, 10, al_map_rgb(222, 138, 114));
	al_put_pixel(11, 11, al_map_rgb(223, 136, 117));
	al_put_pixel(11, 12, al_map_rgb(220, 208, 192));
	al_put_pixel(11, 13, al_map_rgb(217, 204, 185));
	al_put_pixel(11, 14, al_map_rgb(219, 206, 187));
	al_put_pixel(11, 15, al_map_rgb(221, 203, 199));
	al_put_pixel(12, 0, al_map_rgb(226, 201, 181));
	al_put_pixel(12, 1, al_map_rgb(245, 220, 189));
	al_put_pixel(12, 2, al_map_rgb(248, 223, 193));
	al_put_pixel(12, 3, al_map_rgb(246, 221, 191));
	al_put_pixel(12, 4, al_map_rgb(224, 199, 179));
	al_put_pixel(12, 5, al_map_rgb(247, 224, 193));
	al_put_pixel(12, 6, al_map_rgb(247, 221, 194));
	al_put_pixel(12, 7, al_map_rgb(246, 219, 190));
	al_put_pixel(12, 8, al_map_rgb(235, 200, 180));
	al_put_pixel(12, 9, al_map_rgb(249, 214, 195));
	al_put_pixel(12, 10, al_map_rgb(254, 219, 197));
	al_put_pixel(12, 11, al_map_rgb(237, 198, 183));
	al_put_pixel(12, 12, al_map_rgb(230, 219, 199));
	al_put_pixel(12, 13, al_map_rgb(238, 226, 204));
	al_put_pixel(12, 14, al_map_rgb(236, 224, 202));
	al_put_pixel(12, 15, al_map_rgb(215, 201, 192));
	al_put_pixel(13, 0, al_map_rgb(218, 206, 194));
	al_put_pixel(13, 1, al_map_rgb(232, 220, 196));
	al_put_pixel(13, 2, al_map_rgb(220, 208, 186));
	al_put_pixel(13, 3, al_map_rgb(236, 224, 202));
	al_put_pixel(13, 4, al_map_rgb(216, 204, 192));
	al_put_pixel(13, 5, al_map_rgb(235, 224, 202));
	al_put_pixel(13, 6, al_map_rgb(221, 208, 189));
	al_put_pixel(13, 7, al_map_rgb(237, 222, 201));
	al_put_pixel(13, 8, al_map_rgb(217, 204, 188));
	al_put_pixel(13, 9, al_map_rgb(221, 209, 193));
	al_put_pixel(13, 10, al_map_rgb(234, 223, 203));
	al_put_pixel(13, 11, al_map_rgb(216, 202, 189));
	al_put_pixel(13, 12, al_map_rgb(241, 228, 209));
	al_put_pixel(13, 13, al_map_rgb(219, 204, 185));
	al_put_pixel(13, 14, al_map_rgb(237, 222, 199));
	al_put_pixel(13, 15, al_map_rgb(222, 208, 197));
	al_put_pixel(14, 0, al_map_rgb(219, 205, 194));
	al_put_pixel(14, 1, al_map_rgb(236, 224, 202));
	al_put_pixel(14, 2, al_map_rgb(237, 222, 203));
	al_put_pixel(14, 3, al_map_rgb(238, 225, 206));
	al_put_pixel(14, 4, al_map_rgb(216, 203, 194));
	al_put_pixel(14, 5, al_map_rgb(237, 226, 206));
	al_put_pixel(14, 6, al_map_rgb(234, 221, 202));
	al_put_pixel(14, 7, al_map_rgb(240, 225, 204));
	al_put_pixel(14, 8, al_map_rgb(218, 204, 191));
	al_put_pixel(14, 9, al_map_rgb(235, 223, 209));
	al_put_pixel(14, 10, al_map_rgb(232, 224, 203));
	al_put_pixel(14, 11, al_map_rgb(216, 204, 188));
	al_put_pixel(14, 12, al_map_rgb(237, 223, 210));
	al_put_pixel(14, 13, al_map_rgb(239, 224, 205));
	al_put_pixel(14, 14, al_map_rgb(237, 225, 203));
	al_put_pixel(14, 15, al_map_rgb(216, 203, 194));
	al_put_pixel(15, 0, al_map_rgb(218, 204, 193));
	al_put_pixel(15, 1, al_map_rgb(217, 205, 183));
	al_put_pixel(15, 2, al_map_rgb(221, 206, 187));
	al_put_pixel(15, 3, al_map_rgb(217, 204, 185));
	al_put_pixel(15, 4, al_map_rgb(217, 204, 195));
	al_put_pixel(15, 5, al_map_rgb(217, 206, 186));
	al_put_pixel(15, 6, al_map_rgb(217, 204, 185));
	al_put_pixel(15, 7, al_map_rgb(220, 205, 184));
	al_put_pixel(15, 8, al_map_rgb(218, 204, 191));
	al_put_pixel(15, 9, al_map_rgb(217, 205, 191));
	al_put_pixel(15, 10, al_map_rgb(218, 210, 189));
	al_put_pixel(15, 11, al_map_rgb(216, 208, 189));
	al_put_pixel(15, 12, al_map_rgb(218, 201, 191));
	al_put_pixel(15, 13, al_map_rgb(221, 205, 189));
	al_put_pixel(15, 14, al_map_rgb(217, 205, 183));
	al_put_pixel(15, 15, al_map_rgb(217, 204, 195));

	// https://github.com/liballeg/allegro5/blob/b70f37412a082293f26e86ff9c0b6ac7c151d2d0/examples/ex_icon.c#L70
	al_set_target_backbuffer(game_display);

	return icon;
}