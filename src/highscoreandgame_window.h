#include "calculator.h"
#include "tile.h"
#include "tile_screen.h"
#include "../include/Simple_window.h"
#include "../include/std_lib_facilities_4.h"
#include "../include/Graph.h"
#include "../include/GUI.h"
#include "../include/Window.h"


struct List{
	int place;
	string name;
	int score;
};


struct highscore_window : Graph_lib::Window{
	highscore_window(Point xy, int w, int h, const string& title);

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

};

highscore_window::highscore_window(Point xy,int w,int h,const string& title)
:Window{xy,w,h,title},

highscore3{Point{375,35},150,50,"Highscore, Difficulty: 3",
[](Address, Address pw){reference_to<highscore_window>(pw).high3();}},

highscore4{Point{375,105},150,50,"Highscore, Difficulty: 4",
[](Address, Address pw){reference_to<highscore_window>(pw).high4();}},

highscore5{Point{375,175},150,50,"Highscore, Difficulty: 5",
[](Address, Address pw){reference_to<highscore_window>(pw).high5();}},

highscore6{Point{375,245},150,50,"Highscore, Difficulty: 6",
[](Address, Address pw){reference_to<highscore_window>(pw).high6();}},

highscore7{Point{375,315},150,50,"Highscore, Difficulty: 7",
[](Address, Address pw){reference_to<highscore_window>(pw).high7();}},

game3{Point{50,35},150,50,"Game, Difficulty: 3",
[](Address, Address pw){reference_to<highscore_window>(pw).gamefun3();}},

game4{Point{50,105},150,50,"Game, Difficulty: 4",
[](Address, Address pw){reference_to<highscore_window>(pw).gamefun4();}},

game5{Point{50,175},150,50,"Game, Difficulty: 5",
[](Address, Address pw){reference_to<highscore_window>(pw).gamefun5();}},

game6{Point{50,245},150,50,"Game, Difficulty: 6",
[](Address, Address pw){reference_to<highscore_window>(pw).gamefun6();}},

game7{Point{50,315},150,50,"Game, Difficulty: 7",
[](Address, Address pw){reference_to<highscore_window>(pw).gamefun7();}}





	{
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

	void highscore_window::high3()
	{
		Simple_window scores{Point{200,200},400,400,"Highscore, Difficulty: 3"};
		
		ifstream ist{"highscore3.txt"};
		if(!ist)error("cant open");

		vector<List>highscore;
		int place;
		string name;
		int score;

		while(ist>>place>>name>>score){
			highscore.push_back(List{place,name,score});
}

ist.close();
		
		ostringstream one;
		one<<highscore[0].place<<". "<<highscore[0].name<<'-'<<highscore[0].score<<endl;
		Text first{Point{50,70},one.str()};
		first.set_font_size(30);
		first.set_color(Color::yellow);
		scores.attach(first);
		
		ostringstream two;
		two<<highscore[1].place<<". "<<highscore[1].name<<'-'<<highscore[1].score<<endl;
		Text sec{Point{50,145},two.str()};
		sec.set_font_size(30);
		sec.set_color(Color{18});
		scores.attach(sec);
		
		ostringstream three;
		three<<highscore[2].place<<". "<<highscore[2].name<<'-'<<highscore[2].score<<endl;
		Text third{Point{50,220},three.str()};
		third.set_font_size(30);
		third.set_color(Color{74});
		scores.attach(third);
		
		ostringstream four;
		four<<highscore[3].place<<". "<<highscore[3].name<<'-'<<highscore[3].score<<endl;
		Text fourth{Point{50,295},four.str()};
		fourth.set_font_size(30);
		scores.attach(fourth);
		
		ostringstream five;
		five<<highscore[4].place<<". "<<highscore[4].name<<'-'<<highscore[4].score<<endl;
		Text fifth{Point{50,370},five.str()};
		fifth.set_font_size(30);
		scores.attach(fifth);
		
		
		
		scores.wait_for_button();
	}
	
	void highscore_window::high4()
	{
		Simple_window scores{Point{200,200},400,400,"Highscore, Difficulty: 4"};
		ifstream ist{"highscore4.txt"};
		if(!ist)error("cant open");

		vector<List>highscore;
		int place;
		string name;
		int score;

		while(ist>>place>>name>>score){
			highscore.push_back(List{place,name,score});
}

ist.close();
		
		ostringstream one;
		one<<highscore[0].place<<". "<<highscore[0].name<<'-'<<highscore[0].score<<endl;
		Text first{Point{50,70},one.str()};
		first.set_font_size(30);
		first.set_color(Color::yellow);
		scores.attach(first);
		
		ostringstream two;
		two<<highscore[1].place<<". "<<highscore[1].name<<'-'<<highscore[1].score<<endl;
		Text sec{Point{50,145},two.str()};
		sec.set_font_size(30);
		sec.set_color(Color{18});
		scores.attach(sec);
		
		ostringstream three;
		three<<highscore[2].place<<". "<<highscore[2].name<<'-'<<highscore[2].score<<endl;
		Text third{Point{50,220},three.str()};
		third.set_font_size(30);
		third.set_color(Color{74});
		scores.attach(third);
		
		ostringstream four;
		four<<highscore[3].place<<". "<<highscore[3].name<<'-'<<highscore[3].score<<endl;
		Text fourth{Point{50,295},four.str()};
		fourth.set_font_size(30);
		scores.attach(fourth);
		
		ostringstream five;
		five<<highscore[4].place<<". "<<highscore[4].name<<'-'<<highscore[4].score<<endl;
		Text fifth{Point{50,370},five.str()};
		fifth.set_font_size(30);
		scores.attach(fifth);
		
		scores.wait_for_button();
	}
	
	void highscore_window::high5()
	{
		Simple_window scores{Point{200,200},400,400,"Highscore, Difficulty: 5"};
		
		ifstream ist{"highscore5.txt"};
		if(!ist)error("cant open");

		vector<List>highscore;
		int place;
		string name;
		int score;

		while(ist>>place>>name>>score){
			highscore.push_back(List{place,name,score});
}

ist.close();
		
		ostringstream one;
		one<<highscore[0].place<<". "<<highscore[0].name<<'-'<<highscore[0].score<<endl;
		Text first{Point{50,70},one.str()};
		first.set_font_size(30);
		first.set_color(Color::yellow);
		scores.attach(first);
		
		ostringstream two;
		two<<highscore[1].place<<". "<<highscore[1].name<<'-'<<highscore[1].score<<endl;
		Text sec{Point{50,145},two.str()};
		sec.set_font_size(30);
		sec.set_color(Color{18});
		scores.attach(sec);
		
		ostringstream three;
		three<<highscore[2].place<<". "<<highscore[2].name<<'-'<<highscore[2].score<<endl;
		Text third{Point{50,220},three.str()};
		third.set_font_size(30);
		third.set_color(Color{74});
		scores.attach(third);
		
		ostringstream four;
		four<<highscore[3].place<<". "<<highscore[3].name<<'-'<<highscore[3].score<<endl;
		Text fourth{Point{50,295},four.str()};
		fourth.set_font_size(30);
		scores.attach(fourth);
		
		ostringstream five;
		five<<highscore[4].place<<". "<<highscore[4].name<<'-'<<highscore[4].score<<endl;
		Text fifth{Point{50,370},five.str()};
		fifth.set_font_size(30);
		scores.attach(fifth);
		
		scores.wait_for_button();
	}
	
	void highscore_window::high6()
	{
		Simple_window scores{Point{200,200},400,400,"Highscore, Difficulty: 6"};
		
		ifstream ist{"highscore6.txt"};
		if(!ist)error("cant open");

		vector<List>highscore;
		int place;
		string name;
		int score;

		while(ist>>place>>name>>score){
			highscore.push_back(List{place,name,score});
}

ist.close();
		
		ostringstream one;
		one<<highscore[0].place<<". "<<highscore[0].name<<'-'<<highscore[0].score<<endl;
		Text first{Point{50,70},one.str()};
		first.set_font_size(30);
		first.set_color(Color::yellow);
		scores.attach(first);
		
		ostringstream two;
		two<<highscore[1].place<<". "<<highscore[1].name<<'-'<<highscore[1].score<<endl;
		Text sec{Point{50,145},two.str()};
		sec.set_font_size(30);
		sec.set_color(Color{18});
		scores.attach(sec);
		
		ostringstream three;
		three<<highscore[2].place<<". "<<highscore[2].name<<'-'<<highscore[2].score<<endl;
		Text third{Point{50,220},three.str()};
		third.set_font_size(30);
		third.set_color(Color{74});
		scores.attach(third);
		
		ostringstream four;
		four<<highscore[3].place<<". "<<highscore[3].name<<'-'<<highscore[3].score<<endl;
		Text fourth{Point{50,295},four.str()};
		fourth.set_font_size(30);
		scores.attach(fourth);
		
		ostringstream five;
		five<<highscore[4].place<<". "<<highscore[4].name<<'-'<<highscore[4].score<<endl;
		Text fifth{Point{50,370},five.str()};
		fifth.set_font_size(30);
		scores.attach(fifth);
		
		scores.wait_for_button();
	}
	
	void highscore_window::high7()
	{
		Simple_window scores{Point{200,200},400,400,"Highscore, Difficulty: 7"};
		
		ifstream ist{"highscore7.txt"};
		if(!ist)error("cant open");

		vector<List>highscore;
		int place;
		string name;
		int score;

		while(ist>>place>>name>>score){
			highscore.push_back(List{place,name,score});
}

ist.close();
		
		ostringstream one;
		one<<highscore[0].place<<". "<<highscore[0].name<<'-'<<highscore[0].score<<endl;
		Text first{Point{50,70},one.str()};
		first.set_font_size(30);
		first.set_color(Color::yellow);
		scores.attach(first);
		
		ostringstream two;
		two<<highscore[1].place<<". "<<highscore[1].name<<'-'<<highscore[1].score<<endl;
		Text sec{Point{50,145},two.str()};
		sec.set_font_size(30);
		sec.set_color(Color{18});
		scores.attach(sec);
		
		ostringstream three;
		three<<highscore[2].place<<". "<<highscore[2].name<<'-'<<highscore[2].score<<endl;
		Text third{Point{50,220},three.str()};
		third.set_font_size(30);
		third.set_color(Color{74});
		scores.attach(third);
		
		ostringstream four;
		four<<highscore[3].place<<". "<<highscore[3].name<<'-'<<highscore[3].score<<endl;
		Text fourth{Point{50,295},four.str()};
		fourth.set_font_size(30);
		scores.attach(fourth);
		
		ostringstream five;
		five<<highscore[4].place<<". "<<highscore[4].name<<'-'<<highscore[4].score<<endl;
		Text fifth{Point{50,370},five.str()};
		fifth.set_font_size(30);
		scores.attach(fifth);
		
		scores.wait_for_button();
	}
	
	void highscore_window::gamefun3(){
		tile_screen three{(3),Point{200,200},800,600};
		gui_main();
	}
	
	void highscore_window::gamefun4(){
		tile_screen three{(4),Point{200,200},800,600};
		gui_main();
	}
	
	void highscore_window::gamefun5(){
		tile_screen three{(5),Point{200,200},800,600};
		gui_main();
	}
	
	void highscore_window::gamefun6(){
		tile_screen three{(6),Point{200,200},800,600};
		gui_main();
	}
	
	void highscore_window::gamefun7(){
		tile_screen three{(7),Point{200,200},800,600};
		gui_main();
	}
	
	
	