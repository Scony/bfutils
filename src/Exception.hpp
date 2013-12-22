#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>

class Exception
{
public:
  Exception(std::string message);
  Exception(std::string message, int code);
  Exception();
  std::string toString();
  std::string getMessage();
  int getCode();

protected:
  std::string message;
  int code;
};

#endif
