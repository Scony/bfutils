#include "File.hpp"

using namespace std;

File::File(string name) throw(Exception)
{
  file.open(name.c_str(), ifstream::out);
  if(!file.is_open())
    throw Exception("File \"" + name + "\" does not exists !");
}

File::~File()
{
  file.close();
}

string File::toString()
{
  string content = "";
  string line = "";
  while(getline(file,line))
    content += line;

  return content;
}
