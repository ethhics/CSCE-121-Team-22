// calculator.h
// Created: 10/29 by Zach Scott
// Original code by Bjarne Stroupstrup
//
// This file declares calculator-related classes and functions

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "defs.h"

namespace Calculator {

class Token
{
public:
	char kind;        // what kind of token
	double value;     // for numbers: a value
	explicit Token(char ch)    // make a Token from a char
		:kind(ch), value(0) { }
	Token(char ch, double val)     // make a Token from a char and a double
		:kind(ch), value(val) { }
};

class Token_stream
{
public:
	Token_stream();   // make a Token_stream that reads from cin
	Token get();      // get a Token (get() is defined elsewhere)
	void putback(Token t);    // put a Token back
	void clear();     // clear the buffer in case it's full
private:
	bool full;        // is there a Token in the buffer?
	Token buffer;     // here is where we keep a Token put back using putback()
};

static Token_stream ts;         // provides get() and putback()
static stringstream c_in;

double expression();
double primary();
double term();

double calculate(string);

}  // end namespace Calculator

#endif	// CALCULATOR_H
