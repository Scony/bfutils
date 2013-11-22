#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <iostream>

#include "Exception.hpp"
#include "Memory.hpp"

class Interpreter
{
  std::string code;
  int * hash;
  int hashLen;
  Memory memory;
 public:
  Interpreter(std::string code)
    throw(Exception);
  ~Interpreter();
  void run();
};

#endif
