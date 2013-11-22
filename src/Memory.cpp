#include "Memory.hpp"

Memory::Cell::Cell()
{
  cell = new unsigned char(0);
  next = NULL;
  previous = NULL;
}

Memory::Cell::~Cell()
{
  delete cell;
  if(next)
    {
      next->previous = NULL;
      delete next;
    }
  if(previous)
    {
      previous->next = NULL;
      delete previous;
    }
}

Memory::Memory()
{
  head = new Cell;
}

Memory::~Memory()
{
  delete head;
}

void Memory::add()
{
  (*(head->cell))++;
}

void Memory::sub()
{
  (*(head->cell))--;
}

void Memory::write(unsigned char c)
{
  *(head->cell) = c;
}

unsigned char Memory::read()
{
  return *(head->cell);
}

void Memory::next()
{
  if(head->next)
    head = head->next;
  else
    {
      head->next = new Cell;
      head->next->previous = head;
      head = head->next;
    }

  if(!head->previous->previous && *(head->previous->cell) == 0)
    {
      head->previous->next = NULL;
      delete head->previous;
      head->previous = NULL;
    }
}

void Memory::previous()
{
  if(head->previous)
    head = head->previous;
  else
    {
      head->previous = new Cell;
      head->previous->next = head;
      head = head->previous;
    }

  if(!head->next->next && *(head->next->cell) == 0)
    {
      head->next->previous = NULL;
      delete head->next;
      head->next = NULL;
    }
}
