#define _CRT_SECURE_NO_WARNINGS

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "game_resource.h"
#include "game_font.h"

char* resource_extract(char* file_name, char* file_bytes, size_t file_length)
{
	size_t folder_path_length = (size_t)(max(strrchr(game_executable_path, '/'),
		strrchr(game_executable_path, '\\')) - game_executable_path + 1);

	char* file_folder = calloc(folder_path_length + 1, 1);

	if (file_folder == 0)
		return;

	memcpy(file_folder, game_executable_path, folder_path_length);

	char* file_absolute_path = calloc(folder_path_length + strlen(file_name), 1);

	if (file_absolute_path == 0)
		return;

	strcat(file_absolute_path, file_folder);
	strcat(file_absolute_path, file_name);

	FILE* file = fopen(file_absolute_path, "wb");

	fwrite(file_bytes, file_length, 1, file);

	return file_absolute_path;
}