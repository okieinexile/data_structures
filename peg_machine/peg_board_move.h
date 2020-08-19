#ifndef PEG_BOARD_MOVE_H_INCLUDED
#define PEG_BOARD_MOVE_H_INCLUDED

#include"peg_board_turn.h"
#include"move.h"
#include <vector>

class PegBoardMove : public PegBoardTurn
{
  private:
    std::vector<Move> move_stack;
  
  public:
    PegBoardMove(void);
    PegBoardMove(unsigned short int p_state);
    bool move_allowed(Move mv);
    void push_move(Move mv);
    void pop_move(void);
    Move top_move(void);
    void fill_move_stack(void);
    size_t number_of_moves_available(void);
    bool can_move(void);
};

PegBoardMove::PegBoardMove(void) : PegBoardTurn()
{
  this->fill_move_stack();
}

PegBoardMove::PegBoardMove(unsigned short int p_state) : 
PegBoardTurn(p_state)
{
  this->fill_move_stack();
}

bool PegBoardMove::move_allowed(Move mv)
{
  return this->possible(mv.top, mv.middle, mv.bottom);
}

void PegBoardMove::push_move(Move mv)
{
  this->move_stack.push_back(mv);
}

void PegBoardMove::pop_move(void)
{
  this->move_stack.pop_back();
}

Move PegBoardMove::top_move(void)
{
  return this->move_stack.back();
}

void PegBoardMove::fill_move_stack(void)
{
  for(Move mv : Move::all_moves())
  {
    if(this->move_allowed(mv)) 
      this->push_move(mv);
  }
}

size_t PegBoardMove::number_of_moves_available(void)
{
  return this->move_stack.size();
}

bool PegBoardMove::can_move(void)
{
  return this->number_of_moves_available() > 0;
}

#endif