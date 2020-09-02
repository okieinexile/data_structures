#ifndef PBPLAY_H_INCLUDED
#define PBPLAY_H_INCLUDED

#include"../pbmove/pbmove.h"
#include"../pbpossibilities/pbpossibilities.h"

template <size_t SIZE, size_t CELL>
PBPossibilities<SIZE,CELL> make_next_move(PBPossibilities& current)
{
  PBmove<SIZE> mv = current.top_move();
  current.pop_move();
  PBPossibilities<SIZE,CELL> next(current.code());
  next = next.toggle(mv);
}


#endif // PBPLAY_H_INCLUDED