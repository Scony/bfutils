#include "Exception.hpp"

using namespace std;

Exception::Exception(string message)
{
  this->message = message;
  code = 0;
}

Exception::Exception(string message, int code)
{
  this->message = message;
  this->code = code;
}

Exception::Exception()
{
  message = "Exception";
}

string Exception::toString()
{
  return getMessage();
}

string Exception::getMessage()
{
  return message;
}

int Exception::getCode()
{
  return code;
}
