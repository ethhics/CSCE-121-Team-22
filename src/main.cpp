#include "defs.h"
#include "splash_screen.h"
#include "highscore_screen.h"
#include "game_screen.h"

int main()
{
	string name;
	int difficulty;
	double score;
	splash_screen s {Point{100,100}, 800, 600, "Digit Figit"};
	name = gui_main();
	highscore_screen h {Point{100,100}, 800, 600, "Highscores"};
	difficulty = gui_main();
	game_screen g {Point{100,100}, 800, 600, "Game"};
	score = gui_main();
	// Do stuff with the data
	return 0;
}
