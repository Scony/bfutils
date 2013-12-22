#include <iostream>

#include "DynamicMemory.hpp"

DynamicMemory::Cell::Cell()
{
  cell = new unsigned char(0);
  next = NULL;
  previous = NULL;
}

DynamicMemory::Cell::~Cell()
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

DynamicMemory::DynamicMemory()
{
  head = new Cell;
}

DynamicMemory::~DynamicMemory()
{
  delete head;
}

void DynamicMemory::add()
{
  (*(head->cell))++;
}

void DynamicMemory::sub()
{
  (*(head->cell))--;
}

void DynamicMemory::write(unsigned char c)
{
  *(head->cell) = c;
}

unsigned char DynamicMemory::read()
{
  return *(head->cell);
}

void DynamicMemory::next()
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

void DynamicMemory::previous()
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
