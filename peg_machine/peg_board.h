#ifndef PEG_BOARD_H_INCLUDED
#define PEG_BOARD_H_INCLUDED

#include <bitset>

typedef unsigned short int pb_code;

class PegBoard 
{
  private:
    const pb_code SIZE = 15;
    pb_code state;

  public: 
    PegBoard(void);
    PegBoard(pb_code p_state);
    pb_code size(void);
    bool read_cell(size_t index);
    void fill_cell(size_t index);
    void empty_cell(size_t index);
    void toggle_cell(size_t index);
    pb_code code(void);
    int complexity(void);
};

bool operator<(PegBoard pb1, PegBoard pb2);

PegBoard::PegBoard(void)
{
  this->state = 32767;
  this->empty_cell(4);
}

PegBoard::PegBoard(pb_code p_state)
{
  this->state = p_state;
}

pb_code PegBoard::size(void)
{
  return this->SIZE;
}

bool PegBoard::read_cell(size_t index)
{
  return (this->state >> index) & 1;
}

void PegBoard::fill_cell(size_t index)
{
  this->state |= (1UL << index);
}

void PegBoard::empty_cell(size_t index)
{
  this->state &= ~(1UL << index); 
}

void PegBoard::toggle_cell(size_t index)
{
  this->state ^= (1UL << index);
}

pb_code PegBoard::code(void)
{
  return this->state;
}

int PegBoard::complexity(void)
{
  int sum = 0;
  for(size_t i = 0; i < this->size(); ++i)
  {
    if(this->read_cell(i)) ++sum;
  }
  return sum;
}



bool operator<(PegBoard pb1, PegBoard pb2)
{
  return pb1.code() < pb2.code();
}


#endif //PEG_BOARD_H_INCLUDED