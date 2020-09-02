#ifndef OPERATORS_H_INCLUDED
#define OPERATORS_H_INCLUDED

#include"../pbnode/pbnode.h"

template <pb_code SIZE, pb_code CELL> 
bool operator<(PBNode<SIZE,CELL> pbn1, PBNode<SIZE,CELL> pbn2);

template <pb_code SIZE, pb_code CELL> 
bool operator<(PBNode<SIZE,CELL> pbn1, PBNode<SIZE,CELL> pbn2)
{
  return pbn1.board.code() < pbn2.board.code();
}

#endif // OPERATORS_H_INCLUDED
