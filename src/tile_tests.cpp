// tile_tests.cpp
// Created: 10/28 by Zach Scott
//
// This file tests the implementation of tiles in tile.h and tile.cpp

#include "tile.h"
#include "../include/std_lib_facilities_4.h"

using Tile::TileType;
using Tile::Tile;
using Tile::Tileset;

int main() {
  Tile::Tile t0 {TileType::ZERO};
  Tile::Tile t1 {TileType::PLUS};
  Tile::Tile t2 {TileType::NINE};

  cout << t0.getValue() << t1.getValue() << t2.getValue() << endl;

  Tile::Tileset ts;
  ts.add(t0).add(t1).add(t2);

  cout << ts.getValueString() << endl;

  return 0;
}
