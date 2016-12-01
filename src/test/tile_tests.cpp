// tile_tests.cpp
// Created: 10/28 by Zach Scott
//
// This file tests the implementation of tiles in tile.h and tile.cpp

#include "../defs.h"

using Tile::TileType;
using Tile::Tile;
using Tile::Tileset;

int main() {
	for(int i = 3; i < 8; ++i) {
		cout << "Genning 100 tilesets with size " << i << endl;
		int num_loops = 100;
		while(num_loops-- > 0) {
			Tile::Tileset ts(i);  // Make a tileset with i tiles
			cout << ts.getValueString() << " " << ts.getValueDouble() << endl;
		}
	}
	return 0;
}
