// tile.cpp
// Created: 10/27 by Zach Scott
//
// This file defines all of the tile-related classes, etc. declared in tile.h

#include "tile.h"

using Tile::TileType;
using Tile::Tileset;
using Tile::Tile;
using Calculator::calculate;

void Tileset::add_random(int &nums, int &ops, int &parens, int &facts)
{
    bool made_tile = false;
    while (!made_tile) {
        int rand_type = rand() % 4;
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
                if (parens % 2 == 0) tiles.push_back(new Tile(TileType::LPAREN));
                else tiles.push_back(new Tile(TileType::RPAREN));
                made_tile = true;
            }
            break;
        case 3:  // Make a factorial
            if (facts > 0) {
                facts--;
                tiles.push_back(new Tile(TileType::FACTORIAL));
                made_tile = true;
            }
            break;
        }
    }
  // There's a chance it didn't make a tile. So, do it until it has!
}

TileType Tileset::random_number()
{
    int new_number = rand() % 10;  // 0 to 9
    switch (new_number) {
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
    return TileType::ZERO;  // Never reaches here, but g++ error if I don't include this
}

TileType Tileset::random_operator()
{
    int new_operator = rand() % 4;  // ASMD
    switch (new_operator) {
    case 0:
        return TileType::PLUS;
    case 1:
        return TileType::MINUS;
    case 2:
        return TileType::MULTIPLY;
    case 3:
        return TileType::DIVIDE;
    }
    return TileType::PLUS;  // g++ error if not here
}

Tileset::Tileset(int n): num_tiles(n)
{
    //std::srand(std::time(0));
    // Start by finding out how many of each type we will make. The rules:
    // 1. More numbers than operators
    // 2. At least 1 non-factorial operator
    // 3. Even number of parentheses
    // 4. Factorials less than or equal to numbers

    // If there's more numbers than operators, then edge case would be n/2+1
    // numbers and n/2 operators. There's also at least 1 operator, and
    // rand()%m will return at most m-1.
    int num_operators = 1 + rand() % ((num_tiles - 1) / 2);
    int num_numbers = num_tiles - num_operators;

    int num_parens = 0;
    if (((num_operators + 1) / 2) > 0) {  // Don't make parens if not enough operators
        num_parens = 2 * (rand() % ((num_operators + 1) / 2));
    }
    num_operators -= num_parens;  // Remove parentheses from count

    int num_factorials = 0;
    if (num_operators > 1) { // Don't make factorial if not enough operators
        int max_factorials;
        int limit_operators = num_operators - 1; // Either ops can limit,
        int limit_numbers = num_numbers;         // Or nums can
        if (limit_operators > limit_numbers) max_factorials = limit_numbers;
        else max_factorials = limit_operators;

        num_factorials = rand() % max_factorials;
    }
    num_operators -= num_factorials;

    // Now, generate from each type randomly
    while (n-- > 0) {
        add_random(num_numbers, num_operators, num_parens, num_factorials);
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
    if (tile1_location == tiles.end() || tile2_location == tiles.end()) {
        // One or both tiles aren't in the tileset!
        throw std::exception();
    }
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
