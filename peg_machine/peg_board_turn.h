#ifndef PEG_BOARD_TURN_H_INCLUDED
#define PEG_BOARD_TURN_H_INCLUDED

#include"peg_board.h"


class PegBoardTurn : public PegBoard
{
  public:
    PegBoardTurn(void);
    PegBoardTurn(unsigned short int p_state);
    bool possible(size_t top, size_t middle, size_t bottom);
    PegBoardTurn toggle(size_t top, size_t middle, size_t bottom);
};

PegBoardTurn::PegBoardTurn(void) : PegBoard() {/* Do Nothing */}

PegBoardTurn::PegBoardTurn(unsigned short int p_state) : PegBoard(p_state)
{
  /* Do Nothing */
}

bool PegBoardTurn::possible(size_t top, size_t middle, size_t bottom)
{
  return this->read_cell(middle) & (this->read_cell(top) ^ this->read_cell(bottom));
}

PegBoardTurn PegBoardTurn::toggle(size_t top, size_t middle, size_t bottom)
{
  PegBoardTurn new_peg_board(this->code());
  new_peg_board.toggle_cell(top);
  new_peg_board.toggle_cell(middle);
  new_peg_board.toggle_cell(bottom);
  return new_peg_board;
}


#endif //PEG_BOARD_TURN_H_INCLUDED