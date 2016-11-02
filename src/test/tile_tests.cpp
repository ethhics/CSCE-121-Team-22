// tile_tests.cpp
// Created: 10/28 by Zach Scott
//
// This file tests the implementation of tiles in tile.h and tile.cpp

#include "../tile.h"
#include <iostream>

using Tile::TileType;
using Tile::Tile;
using Tile::Tileset;

int main() {
  for(int i = 3; i < 8; ++i) {
    std::cout << "Genning 100 tilesets with size " << i << std::endl;
    int num_loops = 100;
    int seed = std::time(0);
    while(num_loops-- > 0) {
      srand(seed++);
      Tile::Tileset ts(i);  // Make a tileset with i tiles
      std::cout << ts.getValueString() << " " << ts.getValueDouble() << std::endl;
    }
  }
  return 0;
}
