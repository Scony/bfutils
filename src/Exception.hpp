#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>

class Exception
{
public:
  Exception(std::string message);
  Exception();
  std::string toString();

protected:
  std::string message;

};

#endif
