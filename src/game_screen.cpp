// game_screen.cpp
// Created: 11/16 by Zach Scott
//
// This file defines a window from game_screen.h which prints a tileset on the screen.

#include "game_screen.h"
#include <iostream>

using namespace Graph_lib;

// Callback used for tile buttons. Calls move_button
void a_callback(Address own, Address pw)
{
	reference_to<game_screen>(pw).move_button((void *)own);
}

// Move a button
void TileButton::move(Point xy)
{
	int x = xy.x - button->loc.x;
	int y = xy.y - button->loc.y;
	button->move(x, y);
}

// Change the numbers in this method to change where all of the things are
game_screen::game_screen(int num_tiles, Point xy, int w, int h, const string& title, double& score)
	:Window {xy, w, h, title},
	calculate {Point{640,480}, 160, 120, "Calculate!",
	           [](Address, Address pw){reference_to<game_screen>(pw).get_value();}},
	tileset(num_tiles),
	score{score}
{
	const int tile_height = 100;
	const int tile_width = 75;
	const int start_x = 50;
	const int top_y = 100;
	const int bottom_y = 400;
	int i = 0;
	for (Tile::Tile *t : tileset.getTiles()) {
		string s(1, t->getValue());  // Get the tile's value
		// Make a location on the top line for the tile
		Point loc {start_x+tile_width*i, top_y};
		TileButton *tb = new TileButton {nullptr, true, loc};
		Graph_lib::Button *b = new Graph_lib::Button(loc, tile_width, tile_height, s, a_callback);
		attach(*b);
		tb->button = b;
		buttons.push_back(tb);
		// Make a bottom location as well
		TileLocation *tl = new TileLocation {nullptr, Point{start_x+tile_width*i, bottom_y}};
		locations.push_back(tl);
		i++;
	}
	attach(calculate);
}

// Push all tiles to the left
void game_screen::pushTilesLeft()
{
	// Go through each of the locations from left to right
	for (unsigned int i = 0; i < locations.size(); ++i) {
		TileLocation *tl = locations[i];
		if (tl->tilebutton == nullptr) { // If the location doesn't have a tile
			for (unsigned int j = i; j < locations.size(); ++j) {
				// Start there and find the next location that does
				TileLocation *tl_next = locations[j];
				if (tl_next->tilebutton != nullptr) {
					// If we find a non-empty location, take its tile
					tl->tilebutton = tl_next->tilebutton;
					tl_next->tilebutton = nullptr;

					tl->tilebutton->move(tl->loc);
					break;
				}
			}
		}
	}
}

// Move a button to a location
void game_screen::move_button(void *pointer)
{
	// This is pretty bad practice, but it works.
	// Buttons have callback functions attached to them, and they have only 2
	// parameters: a pointer to the window, and a pointer to something else. It
	// turns out, the second pointer is different for all of the buttons.
	// It seems like in memory it goes BUTTON1 POINTER1 BUTTON2 POINTER2, etc.
	// And so this is hoping that pattern continues. It iterates through the
	// button pointers and checks the memory addresses until it's less than one
	// of them, at which point it performs on the button below it.
	for (unsigned int i = 0; i < buttons.size(); ++i) {
		TileButton *tb = buttons[i];
		if ((void *)tb->button < pointer &&
			((i == buttons.size() - 1) || ((void *)buttons[i+1]->button > pointer))) {
			if (tb->on_top_row) {
				tb->move(locations.back()->loc);
				locations.back()->tilebutton = tb;
			} else {
				tb->move(tb->loc);
				std::for_each(locations.begin(), locations.end(),
					[tb](TileLocation *tl){if(tl->tilebutton == tb){tl->tilebutton = nullptr;}});
			}
			tb->on_top_row = !tb->on_top_row;
			break;
		}
	}
	pushTilesLeft();
}

// Check if any tiles are still on the top row
bool game_screen::tiles_on_top()
{
	for (TileButton *tb : buttons) {
		if (tb->on_top_row) {
			return true;
		}
	}
	return false;
}

// Get a string representation of the tiles on bottom
string game_screen::get_string()
{
	stringstream ss;
	for (TileLocation *tl : locations) {
		if (tl->tilebutton == nullptr) { continue; }
		ss << tl->tilebutton->button->label;
	}
	return ss.str();
}

// Get the value of the tiles on bottom
void game_screen::get_value()
{
	// Check that there aren't any tiles left in the top row. (Don't do
	// anything? Forfeit?)
	if (tiles_on_top()) {
		std::cerr << "Tiles left in the top tileset!" << std::endl;
		return;
	}
	// Now, just print out the value of the bottom row
	score = Calculator::calculate(get_string());
	hide();
}
