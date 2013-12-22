#ifndef DYNAMIC_MEMORY_HPP
#define DYNAMIC_MEMORY_HPP

#include "Memory.hpp"

class DynamicMemory : public Memory
{
public:
  DynamicMemory();
  ~DynamicMemory();
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
