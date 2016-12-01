#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "defs.h"
#include "windows.h"

struct List{
	int place;
	string name;
	int score;
};
void get_scores(int difficulty);
void score_sorter(int score, string name, int difficulty);

struct highscore_screen : Graph_lib::Window{
	highscore_screen(Point xy, int w, int h, const string& title, int& difficulty);

private:
	Button highscore3;
	void high3();
	Button highscore4;
	void high4();
	Button highscore5;
	void high5();
	Button highscore6;
	void high6();
	Button highscore7;
	void high7();
	Button game3;
	void gamefun3();
	Button game4;
	void gamefun4();
	Button game5;
	void gamefun5();
	Button game6;
	void gamefun6();
	Button game7;
	void gamefun7(); 
	int& diff;
};

#endif
