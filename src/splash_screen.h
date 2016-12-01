#ifndef SPLASH_H
#define SPLASH_H

#include "defs.h"
#include "windows.h"
using namespace Graph_lib;
 
struct splash_screen : Graph_lib::Window {
          splash_screen(Point xy, int w, int h, const string& title);
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

#endif
