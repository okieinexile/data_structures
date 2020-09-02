#ifndef PBPOSSIBILITIES_H_INCLUDED
#define PBPOSSIBILITIES_H_INCLUDED

#include"../pbmove/pbmove.h"
#include"../pbturn/pbturn.h"

template <size_t SIZE, size_t CELL>
class PBPossibilities 
{
private:
  std::vector<PBMove<SIZE> > move_stack;
  PBTurn<SIZE,CELL> pbt;
public:
  PBPossibilities(void);
  PBPossibilities(pb_code p_state);
  bool move_allowed(PBMove<SIZE> mv);
  void push_move(PBMove<SIZE> mv);
  void pop_move(void);
  PBMove<SIZE> top_move(void);
  void fill_move_stack(void);
  size_t number_of_moves_available(void);
  bool can_move(void);
  pb_code code(void);
};

template <size_t SIZE, size_t CELL>
PBPossibilities<SIZE,CELL>::PBPossibilities(void)
{
  PBTurn<SIZE,CELL> mpbt;
  this->pbt = mpbt;
  this->fill_move_stack();
}

template <size_t SIZE, size_t CELL>
PBPossibilities<SIZE,CELL>::PBPossibilities(pb_code p_state)
{
  PBTurn<SIZE,CELL> mpbt(p_state);
  this->pbt = mpbt;
  this->fill_move_stack();
}

template <size_t SIZE, size_t CELL>
bool PBPossibilities<SIZE,CELL>::move_allowed(PBMove<SIZE> mv)
{
  return this->pbt.possible(mv);
}

template <size_t SIZE, size_t CELL>
void PBPossibilities<SIZE,CELL>::push_move(PBMove<SIZE> mv)
{
  this->move_stack.push_back(mv);
}

template <size_t SIZE, size_t CELL>
void PBPossibilities<SIZE,CELL>::pop_move(void)
{
  this->move_stack.pop_back();
}

template <size_t SIZE, size_t CELL>
PBMove<SIZE> PBPossibilities<SIZE,CELL>::top_move(void)
{
  return this->move_stack.back();
}

template <size_t SIZE, size_t CELL>
void PBPossibilities<SIZE,CELL>::fill_move_stack(void)
{
  for(PBMove<SIZE> mv : PBMove<SIZE>::all_moves())
  {
    if(this->move_allowed(mv)) this->push_move(mv);
  }
}

template <size_t SIZE, size_t CELL>
size_t PBPossibilities<SIZE,CELL>::number_of_moves_available(void)
{
  return this->move_stack.size();
}

template <size_t SIZE, size_t CELL>
bool PBPossibilities<SIZE,CELL>::can_move(void)
{
  return this->number_of_moves_available() > 0;
}

template <size_t SIZE, size_t CELL>
pb_code PBPossibilities<SIZE,CELL>::code(void)
{
  return this->pbt.code();
}

#endif // PBPOSSIBILITIES_H_INCLUDED