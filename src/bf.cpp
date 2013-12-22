#include <iostream>
#include <unistd.h>

#include "Exception.hpp"
#include "File.hpp"
#include "Interpreter.hpp"
#include "SmallInterpreter.hpp"

using namespace std;

// TODO: shared memory for all interpreter calls

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
      	  SmallInterpreter si(value);
      	  si.run();
	}
      else if(file)
	{
	  File f(value);
	  SmallInterpreter si(f.toString());
	  si.run();
	}
      else if(isatty(0))
	{
	  string code = "";
	  string line;
	  cout << ">>> ";
	  while(getline(cin,line))
	    {
	      try
		{
		  SmallInterpreter si(code + line);
		  si.run();
		  code = "";
		  cout << ">>> ";
		}
	      catch(Exception e)
		{
		  if(e.getCode())
		    {
		      code = "";
		      cout << "Error: " << e.getMessage() << "\n>>> ";
		    }
		  else
		    {
		      code += line;
		      cout << "... ";
		    }
		}
	    }
	}
      else
	{
	  string content = "";
	  string line;
	  while(getline(cin,line))
	    content += line;
	  SmallInterpreter si(content);
	  si.run();
	}
    }
  catch(Exception e)
    {
      cout << e.toString() << endl;
      return 1;
    }

  return 0;
}
