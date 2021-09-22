#include "game.h"
#include "logger.h"

int main(int argc, char** argv)
{
	char* executable_path = argv[0];

	game_run(executable_path);

	return 0;
}