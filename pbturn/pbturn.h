#ifndef   PBTURN_H_INCLUDED
#define PBTURN_H_INCLUDED

#include"../peg_board/peg_board.h"
#include"../pbmove/pbmove.h"

template <size_t SIZE, size_t CELL>
class PBTurn : public PegBoard<SIZE,CELL>
{
public:
  PBTurn(void);
  PBTurn(pb_code p_state);
  bool possible(PBMove<SIZE> mv);
  PBTurn<SIZE,CELL> move(PBMove<SIZE> mv);
};

template <size_t SIZE, size_t CELL>
PBTurn<SIZE,CELL>::PBTurn(void) : PegBoard<SIZE,CELL>(){/* Do nothing */}

template <size_t SIZE, size_t CELL>
PBTurn<SIZE,CELL>::PBTurn(pb_code p_state) : PegBoard<SIZE,CELL>(p_state){/* Do nothing */}

template <size_t SIZE, size_t CELL>
bool PBTurn<SIZE,CELL>::possible(PBMove<SIZE> mv)
{
  size_t top = mv.top;
  size_t middle = mv.middle;
  size_t bottom = mv.bottom;
  return this->read_cell(middle) & (this->read_cell(top) ^ this->read_cell(bottom));
}

template <size_t SIZE, size_t CELL>
PBTurn<SIZE,CELL> PBTurn<SIZE,CELL>::move(PBMove<SIZE> mv)
{
  if(!this->possible(mv)) throw "This move is not possible";
  PBTurn<SIZE,CELL> new_turn(this->code());
  new_turn.toggle_cell(mv.top);
  new_turn.toggle_cell(mv.middle);
  new_turn.toggle_cell(mv.bottom);
  return new_turn;
}

#endif // PBTURN_H_INCLUDED