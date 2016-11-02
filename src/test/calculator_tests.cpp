// calculator_tests.cpp
// Created: 10/29 by Zach Scott
//
// This file tests the implementation of the calculator in calculator.h and
// calculator.cpp

#include "../calculator.h"
#include <iostream>

using Calculator::calculate;

int main() {
  std::cout << "Enter an expression ";
  std::string expr;
  while (std::cin >> expr) {
    std::cout << calculate(expr) << std::endl;
    std::cout << "Enter an expression ";
  }
  return 0;
}
