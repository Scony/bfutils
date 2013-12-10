#ifndef SMALL_INTERPRETER_HPP
#define SMALL_INTERPRETER_HPP

#include <map>

#include "Interpreter.hpp"
#include "Exception.hpp"
#include "Memory.hpp"

class SmallInterpreter : public Interpreter
{
public:
  SmallInterpreter(std::string code)
    throw(Exception);
  ~SmallInterpreter();
  void run();

private:
  Memory memory;
  std::map<int, int> hash;
};

#endif
