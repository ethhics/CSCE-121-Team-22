// tile.h
// Created: 10/27 by Zach Scott
//
// This file declares all of the tile-related classes, enums, functions, and
// structs that are defined in tile.cpp

#ifndef TILE_H
#define TILE_H

#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include "calculator.h"

namespace Tile {

static int TileUID = 0;  // Unique identifier for each individual tile

enum TileType {
  // This enum defines all types of tiles and their corresponding character
  ZERO  = '0',
  ONE   = '1',
  TWO   = '2',
  THREE = '3',
  FOUR  = '4',
  FIVE  = '5',
  SIX   = '6',
  SEVEN = '7',
  EIGHT = '8',
  NINE  = '9',
  // Now for the operators, since char is technically a number these still
  // work for enums
  PLUS     = '+',
  MINUS    = '-',
  MULTIPLY = '*',
  DIVIDE   = '/',
  LPAREN   = '(',
  RPAREN   = ')'
};  // end Tile::TileType

class Tile {
  // This class defines a tile as having a type and a value
  // getType() returns the TileType
  // getValue() returns the value of the TileType
  // getUID() returns the tile's UID
 private:
  TileType type;
  int UID;
 public:
  explicit Tile(TileType t): type(t) { UID = TileUID++; }
  TileType getType() { return type; }
  char getValue() { return static_cast<char>(type); }
  int getUID() { return UID; }
};  // end Tile::Tile

class Tileset {
  // This class defines a group of tiles. The value can be calculated by using
  // the calculator.
  // Initialization requires the size of the tileset
  // add_random() adds a random tile to the tileset
  // getTiles() returns the vector of tiles for non-implemented uses
  // swap_tiles(Tile,Tile) swaps the order of two Tiles
  // getValueString() returns a string of all tile values in order
  // getValueDouble() returns getValueString() passed to the calculator
 private:
  std::vector<Tile *> tiles;
  int num_tiles;
  void add_random(int&, int&, int&);
  TileType random_number();
  TileType random_operator();
 public:
  Tileset(int n);
  std::vector<Tile *> getTiles() { return tiles; }
  void swap_tiles(Tile &, Tile &);
  std::string getValueString();
  double getValueDouble();
};  // end Tile::Tileset

}  // end namespace Tile

#endif  // TILE_H
