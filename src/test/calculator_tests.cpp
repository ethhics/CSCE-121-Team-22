// calculator_tests.cpp
// Created: 10/29 by Zach Scott
//
// This file tests the implementation of the calculator in calculator.h and
// calculator.cpp

#include "../defs.h"

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
