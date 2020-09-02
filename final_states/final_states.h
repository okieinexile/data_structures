#ifndef FINAL_STATES_H_INCLUDED
#define FINAL_STATES_H_INCLUDED

#include <vector>
#include <set>
#include"../math/operators.h"
#include"../pbnode/pbnode.h"

template <pb_code SIZE, pb_code CELL>
class FinalStates 
{
public:
  std::set<PBNode<SIZE,CELL> > states;
  std::vector<PBNode<SIZE,CELL> > working;
  FinalStates(void);
  void push_working(PBNode<SIZE,CELL>& node);
  void pop_working(void);
  PBNode<SIZE,CELL>& current(void);
  void push_state(PBNode<SIZE,CELL>& node);
  bool can_move(void);
  bool can_retreat(void);
  void find_final_states(void);
};

template <pb_code SIZE, pb_code CELL>
FinalStates<SIZE,CELL>::FinalStates(void)
{
  PBNode<SIZE,CELL> initial;
  this->push_working(initial);

}

template <pb_code SIZE, pb_code CELL>
void FinalStates<SIZE,CELL>::push_working(PBNode<SIZE,CELL>& node)
{
  this->working.push_back(node);
}

template <pb_code SIZE, pb_code CELL>
void FinalStates<SIZE,CELL>::pop_working(void)
{
  this->working.pop_back();
}

template <pb_code SIZE, pb_code CELL>
PBNode<SIZE,CELL>& FinalStates<SIZE,CELL>::current(void)
{
  return this->working.back();
}

template <pb_code SIZE, pb_code CELL>
void FinalStates<SIZE,CELL>::push_state(PBNode<SIZE,CELL>& node)
{
  this->states.insert(node);
}

template <pb_code SIZE, pb_code CELL>
bool FinalStates<SIZE,CELL>::can_move(void)
{
  return this->current().move_stack.size() > 0;
}

template <pb_code SIZE, pb_code CELL>
bool FinalStates<SIZE,CELL>::can_retreat(void)
{
  return this->working.size() > 1;
}

template <pb_code SIZE, pb_code CELL>
void FinalStates<SIZE,CELL>::find_final_states(void)
{
  while(true)
  {
    if(this->can_move())
    {
      while(this->can_move())
      {
        PBNode<SIZE,CELL> new_node = this->current().next_node();
        this->push_working(new_node);
      }
      this->push_state(this->current());
      //std::cout << this->current().board << std::endl;
    }
    else 
    {
      if(!this->can_retreat())
      {
        break;
      }
      else
      {
        this->pop_working();
      }
    }
  }
}

#endif // FINAL_STATES_H_INCLUDED