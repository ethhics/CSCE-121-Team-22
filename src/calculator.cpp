// calculator.cpp
// Created: 10/29 by Zach Scott
// Original code by Bjarne Stroupstrup
//
// This file implements the functions and classes in calculator.h

#include "calculator.h"

using Calculator::Token;
using Calculator::Token_stream;

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
  :full(false), buffer(0) { }    // no Token in buffer

// putback() puts back...
void Token_stream::putback(Token t) {
  if (full) throw std::exception();
  buffer = t;       // copy t to buffer
  full = true;      // buffer is now full
}

Token Token_stream::get() {
  if (full) {       // do we already have a Token ready?
    // remove token from buffer
    full = false;
    return buffer;
  }

  char ch;
  c_in >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

  switch (ch) {
  case '=':    // for "print"
  case 'x':    // for "quit"
  case '(': case ')': case '+': case '-': case '*': case '/':
    return Token(ch);        // let each character represent itself
  case '.':
  case '0': case '1': case '2': case '3': case '4':
  case '5': case '6': case '7': case '8': case '9':
    c_in.putback(ch);         // put digit back into the input stream
    double val;
    c_in >> val;              // read a floating-point number
    return Token('8', val);   // let '8' represent "a number"
  default:
    throw std::exception();
  }
  return Token('8', 0.0);  // Complaints from g++
}

// deal with numbers and parentheses
double Calculator::primary() {
  Token t = ts.get();
  switch (t.kind) {
    case '(':    // handle '(' expression ')'
      {  // In braces because d is needed only for this case
        double d = expression();
        t = ts.get();
        if (t.kind != ')') throw std::exception();
        return d;
      }
    case '8':            // we use '8' to represent a number
      return t.value;  // return the number's value
    case '-':
      return -primary();
    case '+':
      return primary();
    default:
      throw std::exception();
  }
  return 0.0;  // Complaints from g++
}

// deal with *, /, and %
double Calculator::term() {
  double left = primary();
  Token t = ts.get();        // get the next token from token stream

  while (true) {
    switch (t.kind) {
    case '*':
      left *= primary();
      t = ts.get();
      break;
    case '/':
      {  // In braces because d is needed only for this case
        double d = primary();
        if (d == 0) std::exception();
        left /= d;
        t = ts.get();
        break;
      }
    default:
      ts.putback(t);     // put t back into the token stream
      return left;
    }
  }
}

// deal with + and -
double Calculator::expression() {
  double left = term();      // read and evaluate a Term
  Token t = ts.get();        // get the next token from token stream

  while (true) {
    switch (t.kind) {
    case '+':
      left += term();    // evaluate Term and add
      t = ts.get();
      break;
    case '-':
      left -= term();    // evaluate Term and subtract
      t = ts.get();
      break;
    default:
      if (t.kind != '=') ts.putback(t);  // put t back into the token stream
      return left;       // finally: no more + or -: return the answer
    }
  }
}

double Calculator::calculate(std::string calc_in) {
  c_in.str(std::string());
  c_in.clear();
  c_in << calc_in << "=";
  try {
    return expression();
  } catch(...) {  // There's an error, must be the luser's fault.
    return 0.0;
  }
}
