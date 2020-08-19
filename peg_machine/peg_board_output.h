#ifndef PEG_BOARD_OUTPUT_H_INCLUDED
#define PEG_BOARD_OUTPUT_H_INCLUDED

#include <iostream>
#include <fstream>
//#include"peg_machine/peg_board.h"

std::ostream& operator<<(std::ostream& ost, PegBoard pb);

std::ostream& operator<<(std::ostream& ost, PegBoard pb)
{
  size_t row_length = 1;
  size_t new_row = 0;
  for(size_t i = 0; i < pb.size(); ++i)
  {
    ost << pb.read_cell(i);
    if (!(i < new_row)) 
    { 
      ost << std::endl;
      ++row_length;
      new_row += row_length;
    }
  }
  return ost;
}


#endif // PEG_BOARD_OUTPUT_H_INCLUDED