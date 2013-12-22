#ifndef MEMORY_HPP
#define MEMORY_HPP

class Memory
{
public:
  // Memory();
  virtual ~Memory();
  virtual void add() = 0;
  virtual void sub() = 0;
  virtual void write(unsigned char c) = 0;
  virtual unsigned char read() = 0;
  virtual void next() = 0;
  virtual void previous() = 0;
};

#endif
