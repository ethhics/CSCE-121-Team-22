// calc_test.cpp
// Created: 10/29 by Zach Scott
//
// This file tests the implementation of the calculator in calculator.h and
// calculator.cpp

#include "../include/std_lib_facilities_4.h"
#include "calculator.h"

using Calculator::calculate;

int main() {
  cout << "Enter an expression ";
  string expr;
  while (cin >> expr) {
    cout << calculate(expr) << endl;
    cout << "Enter an expression ";
  }
  return 0;
}
