#define _CRT_SECURE_NO_WARNINGS

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "game_resource.h"
#include "game_font.h"

char* game_get_folder()
{
	char* unix_executable_name = strrchr(game_executable_path, '/') + 1;
	char* nt_executable_name = strrchr(game_executable_path, '\\') + 1;

	char* executable_name = max(unix_executable_name, nt_executable_name);

	size_t folder_path_length = (size_t)(executable_name - game_executable_path);

	char* game_folder = calloc(folder_path_length + 1, 1);

	if (game_folder != 0)
	{
		memcpy(game_folder, game_executable_path, folder_path_length);
	}

	return game_folder;
}

char* resource_extract(char* file_name, char* file_bytes, size_t file_length)
{
	char* file_absolute_path = calloc(strlen(game_folder) + strlen(file_name) + 1, 1);

	if (file_absolute_path != 0)
	{
		strcat(file_absolute_path, game_folder);
		strcat(file_absolute_path, file_name);

		FILE* file = fopen(file_absolute_path, "wb");

		fwrite(file_bytes, file_length, 1, file);
	}

	return file_absolute_path;
}