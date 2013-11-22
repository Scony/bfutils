#include <iostream>
#include <unistd.h>

#include "Exception.hpp"
#include "File.hpp"
#include "Interpreter.hpp"

using namespace std;

int main(int argc, char * argv[])
{
  cin.unsetf(ios::skipws);

  try
    {
      bool code = false;
      bool file = false;
      char * value = NULL;
      int c;
     
      opterr = 0;
      while((c = getopt(argc, argv, "c:")) != -1)
	switch(c)
	  {
	  case 'c':
	    code = true;
	    value = optarg;
	    break;
	  case '?':
	    if(optopt == 'c')
	      cerr << "Option -c requires an argument.\n";
	    else if(isprint(optopt))
	      cerr << "Unknown option `-" << (char)optopt << "'.\n";
	    else
	      cerr << "Unknown option character `\\x" << hex << optopt << "'.\n";
	    return 1;
	  default:
	    throw Exception("getopt() fault");
	  }
     
      if(!code && optind < argc)
	{
	  file = true;
	  value = argv[optind];
	}

      if(code)
	{
      	  Interpreter i(value);
      	  i.run();
	}
      else if(file)
	{
	  File f(value);
	  Interpreter i(f.toString());
	  i.run();
	}
      else if(isatty(0))
	throw Exception("Interactive mode unimplemented");
      else
	{
	  string content = "";
	  string line;
	  while(getline(cin,line))
	    content += line;
	  Interpreter i(content);
	  i.run();
	}
    }
  catch(Exception e)
    {
      cout << e.toString() << endl;
      return 1;
    }

  return 0;
}
