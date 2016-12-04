#include "defs.h"
#include "highscore_screen.h"


void get_scores(int difficulty)
{
	Simple_window scores {Point{200,200},400,400,"Level "+to_string(difficulty)+" Highscores"};
	
	ifstream ist {"data/highscore" + to_string(difficulty) + ".txt"};
	if (!ist) error("cant open");

	vector<List> highscore;
	int place;
	string name;
	int score;

	while (ist >> place >> name >> score)
		highscore.push_back(List{place, name, score});

	ist.close();
	
	ostringstream one;
	one<<highscore[0].place<<". "<<highscore[0].name<<'-'<<highscore[0].score;
	Text first {Point{50,70},one.str()};
	first.set_font_size(30);
	first.set_color(Color::yellow);
	scores.attach(first);
	
	ostringstream two;
	two<<highscore[1].place<<". "<<highscore[1].name<<'-'<<highscore[1].score;
	Text sec {Point{50,145},two.str()};
	sec.set_font_size(30);
	sec.set_color(Color{18});
	scores.attach(sec);
	
	ostringstream three;
	three<<highscore[2].place<<". "<<highscore[2].name<<'-'<<highscore[2].score;
	Text third {Point{50,220},three.str()};
	third.set_font_size(30);
	third.set_color(Color{74});
	scores.attach(third);
	
	ostringstream four;
	four<<highscore[3].place<<". "<<highscore[3].name<<'-'<<highscore[3].score;
	Text fourth {Point{50,295},four.str()};
	fourth.set_font_size(30);
	scores.attach(fourth);
	
	ostringstream five;
	five<<highscore[4].place<<". "<<highscore[4].name<<'-'<<highscore[4].score;
	Text fifth {Point{50,370}, five.str()};
	fifth.set_font_size(30);
	scores.attach(fifth);
	
	scores.wait_for_button();
}
	
void score_sorter(int f, string nam, int difficulty)
{
	ifstream ist {"data/highscore" + to_string(difficulty) + ".txt"};
	if (!ist) error("cant open");

	vector<List> highscore;
	int place;
	string name;
	int score;

	while (ist >> place >> name >> score)
		highscore.push_back(List{place, name, score});
	
	if(f>highscore[4].score) {
	highscore[4].score = f;
	highscore[4].name = nam;
	}
	if(f>highscore[3].score) {
		highscore[4].score = highscore[3].score;
		highscore[3].score = f;
		highscore[4].name = highscore[3].name;
		highscore[3].name = nam;
	}
	if(f>highscore[2].score) {
		highscore[3].score = highscore[2].score;
		highscore[2].score = f;
		highscore[3].name = highscore[2].name;
		highscore[2].name = nam;
	}
	if(f>highscore[1].score) {
		highscore[2].score = highscore[1].score;
		highscore[1].score = f;
		highscore[2].name = highscore[1].name;
		highscore[1].name = nam;
	}
	if(f>highscore[0].score) {
		highscore[1].score = highscore[0].score;
		highscore[0].score = f;
		highscore[1].name = highscore[0].name;
		highscore[0].name = nam;
	}
	
	ofstream ost{"data/highscore" + to_string(difficulty) + ".txt"};
	ost.trunc;

	for(int i = 0; i < highscore.size(); ++i)
		ost << highscore[i].place << '\t' << highscore[i].name << '\t'
			<< highscore[i].score << '\n';
}

highscore_screen::highscore_screen(Point xy,int w,int h,const string& title, int& difficulty)
:Window{xy,w,h,title},
highscore3{Point{475,60},200,75,"Highscore, Difficulty: 3",
	[](Address, Address pw){reference_to<highscore_screen>(pw).high3();}},
highscore4{Point{475,160},200,75,"Highscore, Difficulty: 4",
	[](Address, Address pw){reference_to<highscore_screen>(pw).high4();}},
highscore5{Point{475,260},200,75,"Highscore, Difficulty: 5",
	[](Address, Address pw){reference_to<highscore_screen>(pw).high5();}},
highscore6{Point{475,360},200,75,"Highscore, Difficulty: 6",
	[](Address, Address pw){reference_to<highscore_screen>(pw).high6();}},
highscore7{Point{475,460},200,75,"Highscore, Difficulty: 7",
	[](Address, Address pw){reference_to<highscore_screen>(pw).high7();}},
game3{Point{125,60},200,75,"Game, Difficulty: 3",
	[](Address, Address pw){reference_to<highscore_screen>(pw).gamefun3();}},
game4{Point{125,160},200,75,"Game, Difficulty: 4",
	[](Address, Address pw){reference_to<highscore_screen>(pw).gamefun4();}},
game5{Point{125,260},200,75,"Game, Difficulty: 5",
	[](Address, Address pw){reference_to<highscore_screen>(pw).gamefun5();}},
game6{Point{125,360},200,75,"Game, Difficulty: 6",
	[](Address, Address pw){reference_to<highscore_screen>(pw).gamefun6();}},
game7{Point{125,460},200,75,"Game, Difficulty: 7",
	[](Address, Address pw){reference_to<highscore_screen>(pw).gamefun7();}},
diff{difficulty}
{
	diff = 0;
	attach(highscore3);
	attach(highscore4);
	attach(highscore5);
	attach(highscore6);
	attach(highscore7);
	attach(game3);
	attach(game4);
	attach(game5);
	attach(game6);
	attach(game7);
}

void highscore_screen::high3()
{
	get_scores(3);
}

void highscore_screen::high4()
{
	get_scores(4);
}

void highscore_screen::high5()
{
	get_scores(5);
}

void highscore_screen::high6()
{
	get_scores(6);
}

void highscore_screen::high7()
{
	get_scores(7);
}

void highscore_screen::gamefun3()
{
	diff = 3;
	this->hide();
}

void highscore_screen::gamefun4()
{
	diff = 4;
	this->hide();
}

void highscore_screen::gamefun5()
{
	diff = 5;
	this->hide();
}

void highscore_screen::gamefun6()
{
	diff = 6;
	this->hide();
}

void highscore_screen::gamefun7()
{
	diff = 7;
	this->hide();
}
