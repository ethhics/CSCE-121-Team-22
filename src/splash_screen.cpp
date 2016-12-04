#include "defs.h"
#include "splash_screen.h"

splash_screen::splash_screen(Point xy, int w, int h, const string& title)
	:Graph_lib::Window{xy,w,h,title},
	bg{Point(0,0),"data/faketiles.jpg"},
	banner{Point(200,0),"data/banner.gif"},
	start{Point(350,514), 170, 30},
	qquit{Point{x_max() - 30,0}, 30, 16},
	go{Point(355,540), "Start Game! "},
	end{Point(x_max() - 29, 13), "Quit"},
	numb(Point(20,160), "Team Number 22 "),
	memb(Point(20,190), "Team Members: "),
	name1(Point(20,210), "Joseph Rangel "),
	name2(Point(20,230), "Michael Schmaus "),
	name3(Point(20,250), "Zachary Scott "),
	game_name(Point(320,100), "Digit Figit"),
	assistance(Point(320,495), "Press start game to start"),
	bg2(Point(0,0), 800, 600),
	rules1(Point(30,60), "Rules:"),
	rules2(Point(30,105), "Click on the tile you wish to play."),
	rules3(Point(30,150), "Organize the tiles in a manner that"),
	rules4(Point(30,195), "will create an acceptable expression."),
	rules5(Point(30,240), "You may not use factorial (!) on"),
	rules6(Point(30,285), "a number higher than 9."),
	rules7(Point(30,330), "The goal of the game is"),
	rules8(Point(30,375), "to get the highest score."),
	rules9(Point(30,420), "Press start game and good luck!"),
	rules10(Point(355,540), "Start Game! "),
	toggle_button{Point{350,514}, 170, 30, "Start Game",
		[](Address, Address pw) {reference_to<splash_screen>(pw).toggle();}},
	quit_button{Point{x_max() - 30,0}, 30, 20, "Quit",
		[](Address, Address pw) {reference_to<splash_screen>(pw).quit();}},
	actual_start_button{Point{350,514}, 170, 30, "Start Game",
		[](Address, Address pw) {reference_to<splash_screen>(pw).actual_start();}}
{
	attach(bg);
	attach(banner);
	numb.set_color(Color::white);
	attach(numb);
	memb.set_color(Color::white);
	attach(memb);
	name1.set_color(Color::white);
	attach(name1);
	name2.set_color(Color::white);
	attach(name2);
	name3.set_color(Color::white);
	attach(name3);
	game_name.set_font(Graph_lib::Font::times_bold);
	game_name.set_font_size(35);
	attach(game_name);
	assistance.set_color(Color::white);
	assistance.set_font_size(20);
	attach(assistance);

	start.set_fill_color(Color::yellow);
	attach(start);
	qquit.set_fill_color(Color::yellow);
	attach(qquit);
	go.set_font_size(30);
	attach(go);
	attach(end);
	attach(toggle_button);
	attach(quit_button);		  
}



void splash_screen::quit()
{
	hide();          // curious FLTK idiom to delete window
}

void splash_screen::toggle()
{
	detach(banner);
	detach(bg);
	detach(numb);
	detach(memb);
	detach(name1);
	detach(name2);
	detach(name3);
	detach(game_name);
	detach(start);
	detach(go);
	detach(end);
	detach(toggle_button);
	detach(qquit);
	bg2.set_fill_color(Color::white);
	attach(bg2);

	rules1.set_font(Graph_lib::Font::times_bold);
	rules2.set_font(Graph_lib::Font::times_bold);
	rules3.set_font(Graph_lib::Font::times_bold);
	rules4.set_font(Graph_lib::Font::times_bold);
	rules5.set_font(Graph_lib::Font::times_bold);
	rules6.set_font(Graph_lib::Font::times_bold);
	rules7.set_font(Graph_lib::Font::times_bold);
	rules8.set_font(Graph_lib::Font::times_bold);
	rules9.set_font(Graph_lib::Font::times_bold);
	rules1.set_font_size(45);
	rules2.set_font_size(40);
	rules3.set_font_size(40);
	rules4.set_font_size(40);
	rules5.set_font_size(40);
	rules6.set_font_size(40);
	rules7.set_font_size(40);
	rules8.set_font_size(40);
	rules9.set_font_size(40);
	rules10.set_font_size(30);
	attach(rules1);
	attach(rules2);
	attach(rules3);
	attach(rules4);
	attach(rules5);
	attach(rules6);
	attach(rules7);
	attach(rules8);
	attach(rules9);
	attach(rules10);	
	qquit.set_fill_color(Color::white);		  
	attach(qquit);		  
	attach(end);		  
	attach(actual_start_button);
	redraw();
}

void splash_screen::actual_start()
{
	hide();          // curious FLTK idiom to delete window
}
