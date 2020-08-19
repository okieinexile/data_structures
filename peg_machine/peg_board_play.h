#ifndef PEG_BOARD_PLAY_H_INCLUDED
#define PEG_BOARD_PLAY_H_INCLUDED

#include"peg_board_move.h"
#include"move.h"

class PegBoardPlay : public PegBoardMove
{
  private:
    PegBoardPlay make_move(Move mv);
  public:
    PegBoardPlay(void);
    PegBoardPlay(pb_code p_state);
    PegBoardPlay next_move(void);
};

PegBoardPlay::PegBoardPlay(void) : PegBoardMove(){/* Do Nothing*/}

PegBoardPlay::PegBoardPlay(unsigned short int p_state) : 
PegBoardMove(p_state)
{
  /* Do Nothing */
}

PegBoardPlay PegBoardPlay::make_move(Move mv)
{
  PegBoardPlay pbp(this->code());
  PegBoardTurn pbt = pbp.toggle(mv.top, mv.middle, mv.bottom);
  this->pop_move();
  PegBoardPlay new_pbp(pbt.code());
  return new_pbp;
}

PegBoardPlay PegBoardPlay::next_move(void)
{
  return this->make_move(this->top_move());
}

#endif