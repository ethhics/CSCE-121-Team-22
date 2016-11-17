// tile_screen.cpp
// Created: 11/16 by Zach Scott
//
// This file defines a window from tile_screen.h which prints a tileset on the screen.

#include "tile_screen.h"
#include <iostream>

using namespace Graph_lib;

static int BUTTON_NUMBER = 0;

void a_callback(Address own, Address pw)
{
	cout << own << endl;
	reference_to<tile_screen>(pw).move_button((void *)own);
}

tile_screen::tile_screen(int num_tiles, Point xy, int w, int h, const string& title)
	:Window {xy, w, h, title},
	calculate {Point{600,450}, 150, 100, "Calculate!",
	           [](Address, Address pw){reference_to<tile_screen>(pw).get_value();}},
	tileset(num_tiles)
{
	for (Tile::Tile *t : tileset.getTiles()) {
		string s(1, t->getValue());
		TileButton *tb = new TileButton {nullptr, true};
		Graph_lib::Button *b = new Graph_lib::Button(Point{100+100*BUTTON_NUMBER, 100},
			100, 150, s,
			a_callback);
		cout << b << endl;
		attach(*b);
		tb->button = b;
		buttons.push_back(tb);
		BUTTON_NUMBER++;
	}
	attach(calculate);
}

void tile_screen::move_button(void *pointer)
{
	// This is pretty jank, but it should work.
	// Buttons have callback functions attached to them, and they have only 2
	// parameters: a pointer to the window, and a pointer to something else. It
	// turns out, the second pointer is different for all of the buttons.
	// It seems like in memory it goes BUTTON1 POINTER1 BUTTON2 POINTER2, etc.
	// And so this is hoping that pattern continues. It iterates through the
	// button pointers and checks the memory addresses until it's less than one
	// of them, at which point it performs on the button below it.
	for (unsigned int i = 0; i < buttons.size(); ++i) {
		TileButton *tb = buttons[i];
		if ((void *)tb->button < pointer && ((i == buttons.size() - 1) || ((void *)buttons[i+1]->button > pointer))) {
			if (tb->on_top_row) {
				tb->button->move(0, tb->button->height * 2);
			} else {
				tb->button->move(0, tb->button->height * -2); 
			}
			tb->on_top_row = !tb->on_top_row;
			break;
		}
	}
}

bool tile_screen::tiles_on_top()
{
	for (TileButton *tb : buttons) {
		if (tb->on_top_row) {
			return true;
		}
	}
	return false;
}

string tile_screen::get_string()
{
	// Well, we haven't implemented a way to order the tiles differently, so
	// we'll just return the tileset's string
	return tileset.getValueString();
}

void tile_screen::get_value()
{
	// Check that there aren't any tiles left in the top row. (Don't do
	// anything? Forfeit?)
	if (tiles_on_top()) {
		std::cerr << "Tiles left in the top tileset!" << std::endl;
		return;
	}
	// Now, just print out the value of the bottom row
	std::cout << "Value: " << Calculator::calculate(get_string()) << std::endl;
}

int main()
{
	tile_screen window {7, Point{100,100}, 800, 600, "Tiles"};
	return gui_main();
}
