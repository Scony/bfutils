#ifndef SMALL_INTERPRETER_HPP
#define SMALL_INTERPRETER_HPP

#include <map>

#include "Interpreter.hpp"
#include "Exception.hpp"
#include "Memory.hpp"

class SmallInterpreter : public Interpreter
{
public:
  SmallInterpreter(std::string code, Memory * memory = NULL)
    throw(Exception);
  ~SmallInterpreter();
  void run();

private:
  Memory * memory;
  bool memoryOwner;
  std::map<int, int> hash;
};

#endif
