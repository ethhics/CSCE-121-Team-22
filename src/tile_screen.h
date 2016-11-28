// tile_screen.h
// Created: 11/16 by Zach Scott
//
// This file declares a window which prints a tileset on the screen.

#include <vector>
#include <sstream>
#include "tile.h"
#include "../include/GUI.h"
#include "calculator.h"

// A TileButton is a graphical button that represents a tile
typedef struct
{
	Graph_lib::Button *button;
	bool on_top_row;
	const Point loc;

	void move(Point xy);
} TileButton;

// A TileLocation is a point on the screen representing a location that a
// TileButton can be
typedef struct
{
	TileButton *tilebutton;
	const Point loc;
} TileLocation;

// tile_screen is the main game window. It includes everything to run the game
// by itself.
class tile_screen : Graph_lib::Window
{
private:
	Graph_lib::Button calculate;

	Tile::Tileset tileset;
	vector<TileButton*> buttons;
	vector<TileLocation*> locations;

	string get_string();
	bool tiles_on_top();
	void pushTilesLeft();

public:
	tile_screen(int num_tiles, Point xy, int w, int h, const string& title);
	void get_value();
	void move_button(void *i);
};
