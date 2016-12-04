#include "defs.h"
#include "windows.h"

string get_initials(double score)
{
	string name;
	while(name.size() < 3) {
		Simple_window win {Point{100,100}, 400, 400, "Enter your initals"};

		Text head {Point{50,70}, "Your score: "+to_string(score)};
		head.set_font_size(30);
		win.attach(head);

		Text next {Point{50,100}, "Please enter 3 initials"};
		next.set_font_size(20);
		win.attach(next);

		Graph_lib::In_box initials {Point{175,150}, 100, 40, "Initals"};
		win.attach(initials);

		win.wait_for_button();

		name = initials.get_string().substr(0, 3);
	}
	return name;
}
