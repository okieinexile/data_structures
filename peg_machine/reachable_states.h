#ifndef REACHABLE_STATES_H_INCLUDED
#define REACHABLE_STATES_H_INCLUDED

#include"peg_board_play.h"
#include"tree.h"
#include <vector>
#include <set>

class ReachableStates 
{
  private:
    std::set<PegBoardPlay> final_states;
    std::vector<PegBoardPlay> working;
    size_t count;
  public:
    ReachableStates(PegBoardPlay& my_root);
    void push_working(PegBoardPlay& pbp);
    void pop_working(void);
    void push_final_states(PegBoardPlay& pbp);
    PegBoardPlay& current(void);
    bool can_go_back(void);
    void find_all_final_states(void);
    size_t number_final_states(void);
    std::set<PegBoardPlay> final(void);
    size_t number_of_ways(void);
};

ReachableStates::ReachableStates(PegBoardPlay& my_root)
{
  this->push_working(my_root);
  this->count = 0;
}

void ReachableStates::push_working(PegBoardPlay& pbp)
{
  this->working.push_back(pbp);
}

void ReachableStates::pop_working(void)
{
  this->working.pop_back();
}

void ReachableStates::push_final_states(PegBoardPlay& pbp)
{
  this->final_states.insert(pbp);
}

PegBoardPlay& ReachableStates::current(void)
{
  return this->working.back();
}

bool ReachableStates::can_go_back(void)
{
  return this->working.size() > 0;
}

void ReachableStates::find_all_final_states(void)
{
  while(true)
  {
    if(this->current().can_move())
    {
      while(this->current().can_move())
      {
        PegBoardPlay next = this->current().next_move();
        this->push_working(next);
      }
      this->push_final_states(this->current());
      ++this->count;
    }
    else
    {
      if(!this->can_go_back())
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

size_t ReachableStates::number_final_states(void)
{
  return this->final_states.size();
}

std::set<PegBoardPlay> ReachableStates::final(void)
{
  return this->final_states;
}

size_t ReachableStates::number_of_ways(void)
{
  return this->count;
}
#endif