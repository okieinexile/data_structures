#ifndef PBSTREAM_H_INCLUDED
#define PBSTREAM_H_INCLUDED

#include <iostream>
#include <fstream>
#include"../pbmove/pbmove.h"
#include"../pbmove/pbrows.h"
#include"../pbmove/pbslant.h"
#include"../pbturn/pbturn.h"

template <size_t SIZE, size_t CELL>
std::ostream& operator<<(std::ostream& ost, PegBoard<SIZE,CELL> pb);

template <size_t SIZE>
std::ostream& operator<<(std::ostream& ost, PBMove<SIZE> mv);

template <size_t SIZE>
std::ostream& operator<<(std::ostream& ost, pbrow row);

template <size_t SIZE, size_t CELL>
std::ostream& operator<<(std::ostream& ost, PBTurn<SIZE,CELL> pb)
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

template <size_t SIZE>
std::ostream& operator<<(std::ostream& ost, PBMove<SIZE> mv)
{
  ost << "<" 
      << mv.top << ", "
      << mv.middle << ", "
      << mv.bottom << ">";
  return ost;   
}


std::ostream& operator<<(std::ostream& ost, pbrow row)
{
  for(size_t i = 0 ; i < row.size(); ++i)
  {
    ost << row[i];
    if(i < row.size() - 1) ost << "  ";
  }
  return ost;
}
#endif //PBSTREAM_H_INCLUDED