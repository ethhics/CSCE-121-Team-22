#include "defs.h"
#include "windows.h"

int main()
{
	string name = "EAC";
	int difficulty;
	double score;
	splash_screen s {Point{100,100}, 800, 600, "Digit Figit"};
	gui_main();
	while (true) {
		highscore_screen h {Point{100,100}, 800, 600, "Highscores", difficulty};
		gui_main();
		if (difficulty == 0) return 0;
		game_screen g {difficulty, Point{100,100}, 800, 600, "Game", score};
		gui_main();
		name = get_initials(score);
		score_sorter(score, name, difficulty);
		get_scores(difficulty);
	}
}
