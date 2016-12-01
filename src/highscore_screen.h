#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "defs.h"
#include "windows.h"

struct List{
	int place;
	string name;
	int score;
};


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
	int& diff;
};

#endif
