// tile.cpp
// Created: 10/27 by Zach Scott
//
// This file defines all of the tile-related classes, etc. declared in tile.h

#include "tile.h"

using Tile::Tileset;
using Tile::Tile;

void Tileset::swap_tiles(Tile &t1, Tile &t2) {
  // swap_tiles(Tile,Tile) swaps the order of two Tiles
  // First the vector is searched for the location of t1. Then, it is searched
  // for t2. Finally, t1 is replaced in the vector by t2, and t2 by t1.
  int location_t1;
  int location_t2;
  for (int i = 0; i < tiles.size(); ++i) {
    if (t->getUID() == t1.getUID()) {  // If UIDs are the same, tiles are equal
      location_t1 = i;
    } else if (t->getUID() == t2.getUID()) {  // Might as well check for t2!
      location_t2 = i;
    }
  }
  // TODO(Zach) error if t1 or t2 aren't in the tileset
  Tile *temp_tile = tiles[location_t1];
  tiles[location_t1] = tiles[location_t2];
  tiles[location_t2] = temp_tile;
  delete temp_tile;  // If there's a bug where a tile disappears, remove this
}

string Tileset::getValueString() {
  // getValueString() returns a string of all tile values in order
  // A stringstream is created, and the tiles are iterated through, and their
  // types are appended to the stringstream in order. Then return the string.
  std::stringstream tileset_value;
  for (Tile *t : tiles) {
    tileset_value << t->getValue();
  }
  return tileset_value.str();
}
