#ifndef STATES_H_INCLUDED
#define STATES_H_INCLUDED

#include <vector>
#include"board.h"

/* Declarations */

class State : public Board
{
public:
  State(void);
  State(size_t r);
  State(std::vector<bool> pvec);
  State copy(void);
  void fill_cells(void);
  
};

std::ostream& operator<<(std::ostream& ost, State pstate);

/* Definitions */

State::State(void) : Board()
{
  /* Do nothing */
}

State::State(size_t r) : Board(r)
{
  this->fill_cells();
  this->cells[4] = false;
}

State::State(std::vector<bool> pvec)
{
  this->cells = pvec;
}

State State::copy(void)
{
  State out;
  for(size_t index = 0; index < this->size();  ++index)
  {
    out.cells.push_back(this->read_cell(index));
  }
  out.rank = this->rank;
  return out;
}

 void State::fill_cells(void)
 {
  for(size_t i = 0; i < this->size(); ++i)
    this->cells.push_back(true);
 }

/*  

Associated operator

*/

std::ostream& operator<<(std::ostream& ost, State pstate)
{
  size_t row_length = 1;
  size_t new_row = 0;
  for(size_t i =0; i < pstate.cells.size(); ++i)
  {
    ost << pstate.read_cell(i);
    if (!(i < new_row)) 
    { 
      ost << std::endl;
      ++row_length;
      new_row += row_length;
    }
  }
  return ost;
}

#endif