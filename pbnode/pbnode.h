#ifndef PBNODE_H_INCLUDED
#define PBNODE_H_INCLUDED

#include"../pbturn/pbturn.h"
#include"../pbmove/pbmove.h"
#include <vector>

template <pb_code SIZE, pb_code CELL>
class PBNode 
{
public:
  PBTurn<SIZE,CELL> board;
  std::vector<PBMove<SIZE> > move_stack;
  PBNode(void);
  PBNode(PBTurn<SIZE,CELL> myturn);
  void fill_stack(void);
  void push_move(PBMove<SIZE> mv);
  void pop_move(void);
  PBMove<SIZE> top_move(void);
  PBNode<SIZE,CELL> next_node(void);
};

template <pb_code SIZE, pb_code CELL>
PBNode<SIZE,CELL>::PBNode(void)
{
  PBTurn<SIZE,CELL> myturn;
  this->board = myturn;
  this->fill_stack();
}

template <pb_code SIZE, pb_code CELL>
PBNode<SIZE,CELL>::PBNode(PBTurn<SIZE,CELL> myturn)
{
  this->board = myturn;
  this->fill_stack();
}

template <pb_code SIZE, pb_code CELL>
void PBNode<SIZE,CELL>::fill_stack(void)
{
  for(PBMove<SIZE> mv : PBMove<SIZE>::all_moves())
  {
    if(this->board.possible(mv)) this->push_move(mv);
  }
}

template <pb_code SIZE, pb_code CELL>
void PBNode<SIZE,CELL>::push_move(PBMove<SIZE> mv)
{
  this->move_stack.push_back(mv);
}

template <pb_code SIZE, pb_code CELL>
void PBNode<SIZE,CELL>::pop_move(void)
{
  this->move_stack.pop_back();
}

template <pb_code SIZE, pb_code CELL>
PBMove<SIZE> PBNode<SIZE,CELL>::top_move(void)
{
  return this->move_stack.back();
}

template <pb_code SIZE, pb_code CELL>
PBNode<SIZE,CELL> PBNode<SIZE,CELL>::next_node(void)
{
  PBMove<SIZE> mv = this->top_move();
  this->pop_move();
  PBTurn<SIZE,CELL> next_turn = this->board.move(mv);
  PBNode<SIZE,CELL> out(next_turn);
  return out;
}

#endif  //PBNODE_H_INCLUDED