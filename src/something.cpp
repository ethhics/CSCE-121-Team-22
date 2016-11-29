#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities_4.h"
#include "GUI.h"
using namespace Graph_lib;
 
struct Lines_window : Graph_lib::Window {
          Lines_window(Point xy, int w, int h, const string& title);
          Open_polyline lines;
private:
 //First screen for the most part.
		  Image bg;
		  Image banner;
		  Rectangle start;
		  Rectangle qquit;
		  Text go;
		  Text end;
		  Text numb;
		  Text memb;
		  Text name1;
		  Text name2;
		  Text name3;
		  Text game_name;
		  Text assistance;
// Second screen for the most part.		  
		  Rectangle bg2;
		  Text rules1;
		  Text rules2;
		  Text rules3;
		  Text rules4;
		  Text rules5;
		  Text rules6;
		  Text rules7;
		  Text rules8;
		  Text rules9;
		  Text rules10;
		  
		  
		  
		  Button toggle_button;          // add (next_x,next_y) to lines
          Button quit_button;		  		  
		  Button actual_start_button;

          void toggle();
          void quit();
		  void actual_start();
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
          :	Graph_lib::Window{xy,w,h,title},
		  bg{Point(0,0),"faketiles.jpg"},
		  banner{Point(100,0),"banner.gif"},
		  numb(Point(20,120), "Team Number 22 "),
		  memb(Point(20,140), "Team Members: "),
		  name1(Point(20,160), "Joseph Rangel "),
		  name2(Point(20,180), "Michael Schmaus "),
		  name3(Point(20,200), "Zachary Scott "),
		  game_name(Point(220,98), "Digit Figit"),
		  bg2(Point(0,0), 600, 400),
		  rules1(Point(30,40), "Rules:"),
		  rules2(Point(30,75), "Click on the tile you wish to play."),
		  rules3(Point(30,110), "Organize the tiles in a manner that"),
		  rules4(Point(30,145), "will create an acceptable opperation."),
		  rules5(Point(30,180), "You may not use factorial (!) on"),
		  rules6(Point(30,215), "a number higher than 9."),
		  rules7(Point(30,250), "The goal of the game is"),
		  rules8(Point(30,285), "to get the highest score."),
		  rules9(Point(30,320), "Press start game and good luck!"),
		  rules10(Point(310,360), "Start Game! "),
		  assistance(Point(270,345), "Press start game to start"),
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  start{Point(305,347), 88, 16},
		  qquit{Point{x_max() - 30,0}, 30, 16},
		  go{Point(310,360), "Start Game! "},
		  end{Point(x_max() - 29, 13), "Quit"},
		  toggle_button{Point{305,347}, 88, 16, "Start Game",
		  [](Address, Address pw) {reference_to<Lines_window>(pw).toggle();}},
          quit_button{Point{x_max() - 30,0}, 30, 20, "Quit",
		  [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
		  actual_start_button{Point{305,347}, 88, 16, "Start Game",
		  [](Address, Address pw) {reference_to<Lines_window>(pw).actual_start();}}
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
		  attach(assistance);
		  
		  start.set_fill_color(Color::yellow);
		  attach(start);
		  qquit.set_fill_color(Color::yellow);
		  attach(qquit);
		  attach(go);
		  attach(end);
		  attach(toggle_button);
          attach(quit_button);		  
}



void Lines_window::quit()
{
          hide();          // curious FLTK idiom to delete window
}

void Lines_window::toggle()
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
		  rules1.set_font_size(35);
		  rules2.set_font_size(30);
		  rules3.set_font_size(30);
		  rules4.set_font_size(30);
		  rules5.set_font_size(30);
		  rules6.set_font_size(30);
		  rules7.set_font_size(30);
		  rules8.set_font_size(30);
		  rules9.set_font_size(30);
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
//		  if (out.fill_color().as_int() == Graph_lib::Color::white){
//			out.set_fill_color(Graph_lib::Color::black);
//		  }
//		  else 
//			  out.set_fill_color(Graph_lib::Color::white);
//          redraw();
//		  hide();
}

void Lines_window::actual_start()
{
          hide();          // curious FLTK idiom to delete window
}

int main()
try {
          Lines_window win {Point{100,100},600,400,"lightbulb"};
          return gui_main();
}
catch(exception& e) {
          cerr << "exception: " << e.what() << '\n';
          return 1;
}
catch (...) {
          cerr << "Some exception\n";
          return 2;
}