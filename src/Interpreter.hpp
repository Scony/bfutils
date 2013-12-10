#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <iostream>

class Interpreter
{
public:
  Interpreter(std::string code);
  virtual ~Interpreter();
  virtual void run() = 0;

protected:
  std::string code;
};

#endif
