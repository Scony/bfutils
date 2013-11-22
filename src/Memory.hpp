#ifndef MEMORY_HPP
#define MEMORY_HPP

#include<iostream>

//todo: strategia oszczedzania pamieci na skrajach

class Memory
{
  struct Cell
  {
    unsigned char * cell;
    Cell * next;
    Cell * previous;
    Cell();
    ~Cell();
  };
  Cell * head;
 public:
  Memory();
  ~Memory();
  void add();
  void sub();
  void write(unsigned char val);
  unsigned char read();
  void next();
  void previous();
};

#endif
