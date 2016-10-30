// tile.cpp
// Created: 10/27 by Zach Scott
//
// This file defines all of the tile-related classes, etc. declared in tile.h

#include "tile.h"

using Tile::TileType;
using Tile::Tileset;
using Tile::Tile;
using Calculator::calculate;

void Tileset::add_random(int &nums, int &ops, int &parens) {
  bool made_tile = false;
  while (!made_tile) {
    int rand_type = rand() % 3;
    switch (rand_type) {
      case 0:  // Make a number
        if (nums > 0) {
          nums--;
          tiles.push_back(new Tile(random_number()));
          made_tile = true;
        }
        break;
      case 1:  // Make an operator
        if (ops > 0) {
          ops--;
          tiles.push_back(new Tile(random_operator()));
          made_tile = true;
        }
        break;
      case 2:  // Make a paren
        if (parens > 0) {
          parens--;  // Split odd and even so that there's matching parens
          if (parens % 2 == 0) { tiles.push_back(new Tile(TileType::LPAREN)); }
          else { tiles.push_back(new Tile(TileType::RPAREN)); }
          made_tile = true;
        }
        break;
    }
  }
  // There's a chance it didn't make a tile. So, do it until it has!
}

TileType Tileset::random_number() {
  int new_number = rand() % 10;  // 0 to 9
  switch (new_number) {  // TODO(Zach) make this a more elegant solution
    case 0:
      return TileType::ZERO;
    case 1:
      return TileType::ONE;
    case 2:
      return TileType::TWO;
    case 3:
      return TileType::THREE;
    case 4:
      return TileType::FOUR;
    case 5:
      return TileType::FIVE;
    case 6:
      return TileType::SIX;
    case 7:
      return TileType::SEVEN;
    case 8:
      return TileType::EIGHT;
    case 9:
      return TileType::NINE;
  }
  return TileType::ZERO;  // TODO(Zach) error if it reaches here (not a number)
}

TileType Tileset::random_operator() {
  int new_operator = rand() % 4;  // ASMD
  switch (new_operator) {  // TODO(Zach) make this a more elegant solution
    case 0:
      return TileType::PLUS;
    case 1:
      return TileType::MINUS;
    case 2:
      return TileType::MULTIPLY;
    case 3:
      return TileType::DIVIDE;
  }
  return TileType::PLUS;  // TODO(Zach) erro if it reaches here (not an op)
}

Tileset::Tileset(int n): num_tiles(n) {
  //std::srand(std::time(0));
  // Start by finding out how many of each type we will make. The rules:
  // 1. More numbers than operators
  // 2. At least 1 operator
  // 3. Even number of parentheses
  int num_operators = 1 + (rand() % ((num_tiles - 1) / 2));
  int num_parens = 0;
  if (((num_operators + 1) / 2) > 0) {  // Don't make parens if not enough operators
    num_parens = 2 * (rand() % ((num_operators + 1) / 2));
  }
  int num_numbers   = num_tiles - num_operators;

  num_operators -= num_parens;  // Remove parentheses from count

  // Now, generate from each type randomly
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

double Tileset::getValueDouble() {
  // Use the code in calculator.cpp and its corresponding .h file to calculate
  // the value of our tileset
  return calculate(getValueString());
}
