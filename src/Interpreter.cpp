#include <stack>

#include "Interpreter.hpp"

using namespace std;

Interpreter::Interpreter(string code) throw(Exception)
{
  this->code = code;
  hashLen = code.length();
  hash = new int[hashLen];
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

Interpreter::~Interpreter()
{
  delete [] hash;
}

void Interpreter::run()
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
	cin >> c;
	memory.write(c);
	break;
      case '.':
	cout << memory.read();
	break;
      case '[':
	if(!memory.read())
	  i = hash[i] + 1;
	break;
      case ']':
	if(memory.read())
	  i = hash[i];
	break;
      }
}
