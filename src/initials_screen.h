#include "defs.h"
#include "windows.h"
string get_initials(){
	string nam;
	
		while(nam.size()<3){
	Simple_window win{Point{100,100},400,400,"Initial test"};
	
	ostringstream prompt;
	prompt<<"Please enter 3 initials"<<endl;
	Text head{Point{50,70},prompt.str()};
	head.set_font_size(30);
	win.attach(head);

	Graph_lib::In_box initials{Point{175,150},100,40,"Initials"};
	win.attach(initials);
	
	win.wait_for_button();
	 
	nam= initials.get_string().substr(0,3);
		}
    return nam;
}
