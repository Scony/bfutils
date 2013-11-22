#ifndef MEMORY_HPP
#define MEMORY_HPP

#include<iostream>

class Memory
{
public:
  Memory();
  ~Memory();
  void add();
  void sub();
  void write(unsigned char c);
  unsigned char read();
  void next();
  void previous();

protected:
  struct Cell
  {
    unsigned char * cell;
    Cell * next;
    Cell * previous;
    Cell();
    ~Cell();
  };
  Cell * head;
};

#endif
