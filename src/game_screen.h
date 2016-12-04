#ifndef GAME_H
#define GAME_H

#include "defs.h"
#include "windows.h"
#include <FL/Fl_GIF_Image.H>
#include <FL/Fl_JPEG_Image.H>

struct TileButton : Graph_lib::Button
{
	TileButton(Point xy, int w, int h, const string& label, Callback cb)
		: Graph_lib::Button(xy,w,h,label,cb),
		on_top_row{true},
		loc{xy}
	{}

	void move_to(const Point &xy);
	void add_image(const string& s);
	void add_tile(Tile::Tile *t) { tile = t; }

	bool on_top_row;
	const Point loc;
	Tile::Tile *tile;
};

// A TileLocation is a point on the screen representing a location that a
// TileButton can be
typedef struct
{
	TileButton *tilebutton;
	const Point loc;
} TileLocation;

// game_screen is the main game window. It includes everything to run the game
// by itself.
class game_screen : Graph_lib::Window
{
private:
	Graph_lib::Button calculate;

	Tile::Tileset tileset;
	vector<TileButton*> buttons;
	vector<TileLocation*> locations;
	double& score;

	string get_string();
	bool tiles_on_top();
	void pushTilesLeft();

public:
	game_screen(int num_tiles, Point xy, int w, int h, const string& title, double& score);
	void get_value();
	void move_button(void *i);
};

#endif
