#include <stack>

#include "SmallInterpreter.hpp"
#include "DynamicMemory.hpp"

using namespace std;

SmallInterpreter::SmallInterpreter(string code, Memory * memory) throw(Exception) :
  Interpreter(code)
{
  if(memory)
    {
      this->memory = memory;
      memoryOwner = false;
    }
  else
    {
      this->memory = new DynamicMemory;
      memoryOwner = true;
    }

  stack<int> hill;
  for(int i = 0; i < (int)code.length(); i++)
    {
      if(code[i] == '[')
	hill.push(i);
      if(code[i] == ']')
	{
	  if(hill.empty())
	    throw Exception("Unexpected bracket",1);
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
  if(memoryOwner)
    delete memory;
}

void SmallInterpreter::run()
{
  for(int i = 0; i < (int)code.length(); i++)
    switch(code[i])
      {
      case '+':
	memory->add();
	break;
      case '-':
	memory->sub();
	break;
      case '>':
	memory->next();
	break;
      case '<':
	memory->previous();
	break;
      case ',':
	unsigned char c;
	if(!(cin >> c))
	  c = 255;
	memory->write(c);
	break;
      case '.':
	cout << memory->read();
	break;
      case '[':
	if(!memory->read())
	  i = hash[i];
	break;
      case ']':
	if(memory->read())
	  i = hash[i];
	break;
      }
}
