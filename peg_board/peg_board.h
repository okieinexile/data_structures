#ifndef PEG_BOARD_H_INCLUDED
#define PEG_BOARD_H_INCLUDED


typedef unsigned long int pb_code;

template <pb_code SIZE, pb_code CELL>
class PegBoard 
{
private:
  pb_code state;

public:
  PegBoard(void);
  PegBoard(pb_code p_state);
  pb_code size(void);
  pb_code code(void);
  bool read_cell(pb_code index);
  void fill_cell(pb_code index);
  void empty_cell(pb_code index);
  void toggle_cell(pb_code index);
  int complexity(void);
};

template <pb_code SIZE, pb_code CELL>
bool operator<(PegBoard<SIZE, CELL> pb1, PegBoard<SIZE, CELL> pb2);

template <pb_code SIZE, pb_code CELL>
PegBoard<SIZE, CELL>::PegBoard(void)
{
  this->state = (1 << SIZE) - 1;
  this->empty_cell(CELL);
}

template <pb_code SIZE, pb_code CELL>
PegBoard<SIZE, CELL>::PegBoard(pb_code p_state)
{
  this->state = p_state;
}

template <pb_code SIZE, pb_code CELL>
pb_code PegBoard<SIZE, CELL>::size(void)
{
  return SIZE;
}

template <pb_code SIZE, pb_code CELL>
pb_code PegBoard<SIZE, CELL>::code(void)
{
  return this->state;
}

template <pb_code SIZE, pb_code CELL>
bool PegBoard<SIZE, CELL>::read_cell(pb_code index)
{
  return (this->state >> index) & 1;
}

template <pb_code SIZE, pb_code CELL>
void PegBoard<SIZE, CELL>::fill_cell(pb_code index)
{
  this->state |= (1UL << index);
}

template <pb_code SIZE, pb_code CELL>
void PegBoard<SIZE, CELL>::empty_cell(pb_code index)
{
  this->state &= ~(1UL << index); 
}

template <pb_code SIZE, pb_code CELL>
void PegBoard<SIZE, CELL>::toggle_cell(pb_code index)
{
  this->state ^= (1UL << index);
}

template <pb_code SIZE, pb_code CELL>
int PegBoard<SIZE, CELL>::complexity(void)
{
  int sum = 0;
  for(pb_code i = 0; i < this->size(); ++i)
  {
    if(this->read_cell(i)) ++sum;
  }
  return sum;
}

#endif