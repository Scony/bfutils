#ifndef FILE_HPP
#define FILE_HPP

#include <fstream>

#include "Exception.hpp"

class File
{
public:
  File(const std::string fileName)
    throw(Exception);
  ~File();
  std::string toString();

protected:
  std::ifstream file;
};

#endif
