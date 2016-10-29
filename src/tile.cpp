// tile.cpp
// Created: 10/27 by Zach Scott
//
// This file defines all of the tile-related classes, etc. declared in tile.h

#include "tile.h"

using Tile::TileType
using Tile::Tileset;
using Tile::Tile;

void Tileset::add_random(int nums, int ops, int parens) {
  /*
   * So this is a mess of logic, that I'll explain the rationale behind in this
   * comment block. I have a specific case for every situation and what should
   * happen. The cases and results are:
   * 1. 1 less than full ops and paren 1 = operator (paren)
   * 2. 1 less than full tiles and paren 1 = operator (paren)
   * 3. full ops and paren 2 or paren 0 = number (paren 1 is an error)
   * 4. ops < full and rolled ops and paren 1 = operator (might be paren)
   * 5. ops < full and rolled ops and paren 2 = operator (no paren)
   * 6. ops < full and rolled ops and paren 0 = operator
   * 7. ops < full and rolled num = number
   *
   * Those cases are what are represented in the logical mess below. I'll
   * include a comment of what number each statement represents.
   */
  int full_ops = num_tiles / 2;
  int rolled = rand() % 2;
  if ((ops == (full_ops - 1) && parens == 1) ||  // Case 1
      ((ops + nums) == (num_tiles - 1) && parens == 1)) {  // Case 2
    tiles.push_back(new Tile {Tile::TileType::RPAREN});  // Both make a paren
  } else if (ops == full_ops && (parens % 2 == 0)) {  // Case 3
    tiles.push_back(new Tile {random_number()});
  } else if (ops < full_ops && rolled == 0) {  // Depends on paren value
    tiles.push_back(new Tile {random_operator(parens)});  // Let it sort it out!
  } else if (ops < full_ops && rolled == 1) {  // Case 7
    tiles.push_back(new Tile {random_number()});
  } else {
    // That should cover everything, throw an exception if it doesn't
    // TODO(Zach) Throw an exception
  }
}

TileType Tileset::random_number() {
  int new_number = rand() % 10;  // 0 to 9
  switch (new_number) {  // TODO(Zach) make this a more elegant solution
    case 0:
      return Tile::TileType::ZERO;
    case 1:
      return Tile::TileType::ONE;
    case 2:
      return Tile::TileType::TWO;
    case 3:
      return Tile::TileType::THREE;
    case 4:
      return Tile::TileType::FOUR;
    case 5:
      return Tile::TileType::FIVE;
    case 6:
      return Tile::TileType::SIX;
    case 7:
      return Tile::TileType::SEVEN;
    case 8:
      return Tile::TileType::EIGHT;
    case 9:
      return Tile::TileType::NINE;
  }
}

TileType Tileset::random_operator(int paren_num) {
  bool allow_parens = paren_num < 2;  // Don't generate parens when there's 2
  int new_operator = rand() % (allow_parens ? 5 : 4);  // ASMD, possibly with (
  switch (new_operator) {  // TODO(Zach) make this a more elegant solution
    case 0:
      return Tile::TileType::PLUS;
    case 1:
      return Tile::TileType::MINUS;
    case 2:
      return Tile::TileType::MULTIPLY;
    case 3:
      return Tile::TileType::DIVIDE;
    case 4:
      if (paren_num == 0) {  // Make an LPAREN first,
        return Tile::TileType::LPAREN;
      } else {               // And an RPAREN second.
        return Tile::TileType::RPAREN;
      }  // TODO(Zach) bug if somehow more than 2 parens get over to this step
  }
}

Tileset::Tileset(int n): num_tiles(n) {
  // While we have tiles to make, generate a random tile
  int num_numbers   = 0;
  int num_operators = 0;
  int num_parens = 0;
  while (n-- > 0) {
    add_random(num_numbers, num_operators, num_parens);
  }
}

void Tileset::swap_tiles(Tile &t1, Tile &t2) {
  // swap_tiles(Tile,Tile) swaps the order of two Tiles
  // First the vector is searched for the location of t1. Then, it is searched
  // for t2. Finally, t1 is replaced in the vector by t2, and t2 by t1.
  std::vector<Tile *>::iterator tile1_location = tiles.begin();
  std::vector<Tile *>::iterator tile2_location = tiles.begin();
  for (; tile1_location != tiles.end(); ++tile1_location) {
    if ((*tile1_location)->getUID() == t1.getUID()) {  // UIDs define equality
      break;  // We know where the tile is! Keep the iterator where it is
    }
  }
  for (; tile2_location != tiles.end(); ++tile2_location) {
    if ((*tile2_location)->getUID() == t2.getUID()) {
      break;  // We know where the tile is! Keep the iterator where it is
    }
  }
  // TODO(Zach) error if t1 or t2 aren't in the tileset
  std::iter_swap(tile1_location, tile2_location);
}

std::string Tileset::getValueString() {
  // getValueString() returns a string of all tile values in order
  // A stringstream is created, and the tiles are iterated through, and their
  // types are appended to the stringstream in order. Then return the string.
  std::stringstream tileset_value;
  for (Tile *t : tiles) {
    tileset_value << t->getValue();
  }
  return tileset_value.str();
}
