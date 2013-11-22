#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <iostream>

#include "Exception.hpp"
#include "Memory.hpp"

// todo: hash array -> map or hash_map

class Interpreter
{
public:
  Interpreter(std::string code)
    throw(Exception);
  ~Interpreter();
  void run();
protected:
  Memory memory;
  int hashLen;
  int * hash;
  std::string code;
};

#endif
