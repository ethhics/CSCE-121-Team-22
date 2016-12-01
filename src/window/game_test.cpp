#include "../defs.h"
#include "../windows.h"

int main()
{
	// The first number is the number of tiles, this is where input goes
	double score;
	game_screen window {7, Point{100,100}, 800, 600, "Tiles", score};
	return gui_main();
}
