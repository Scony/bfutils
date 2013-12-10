#include <stack>

#include "SmallInterpreter.hpp"

using namespace std;

SmallInterpreter::SmallInterpreter(string code) throw(Exception) :
  Interpreter(code)
{
  stack<int> hill;
  for(int i = 0; i < (int)code.length(); i++)
    {
      if(code[i] == '[')
	hill.push(i);
      if(code[i] == ']')
	{
	  if(hill.empty())
	    throw Exception("Unexpected bracket");
	  else
	    {
	      hash[hill.top()] = i;
	      hash[i] = hill.top();
	      hill.pop();
	    }
	}
    }
  if(!hill.empty())
    throw Exception("Too much brackets");
}

SmallInterpreter::~SmallInterpreter()
{
}

void SmallInterpreter::run()
{
  for(int i = 0; i < (int)code.length(); i++)
    switch(code[i])
      {
      case '+':
	memory.add();
	break;
      case '-':
	memory.sub();
	break;
      case '>':
	memory.next();
	break;
      case '<':
	memory.previous();
	break;
      case ',':
	unsigned char c;
	if(!(cin >> c))
	  c = 255;
	memory.write(c);
	break;
      case '.':
	cout << memory.read();
	break;
      case '[':
	if(!memory.read())
	  i = hash[i];
	break;
      case ']':
	if(memory.read())
	  i = hash[i];
	break;
      }
}
