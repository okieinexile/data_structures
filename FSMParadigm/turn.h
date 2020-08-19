#ifndef Turn_H_INCLUDED
#define Turn_H_INCLUDED

#include"moves.h"
#include"states.h"
#include"move_possibilities.h"
#include <vector>


class Turn
{
private:
  MovePossibilities possibilities;

public:
  Turn(void);
  Turn(size_t rank);
  Turn(State pstate);
  State do_up(Move mv);
  State do_down(Move mv);
  State do_move(Move mv);
  State make_move(void);
  bool move_available(void);
  size_t number_of_moves_left(void);
  bool solved(void);
  State show(void);
  Turn go_to_the_next_turn(void);
  Move& top_move(void);
};

Turn::Turn(void)
{
  /* Do Nothing */
}

Turn::Turn(size_t rank)
{
  State my_state(rank);
  MovePossibilities mp(my_state);
  this->possibilities = mp;
}

Turn::Turn(State pstate)
{
  MovePossibilities mp(pstate);
  this->possibilities = mp;
}

State Turn::do_up(Move mv)
{
  State my_state = this->show();
  if(this->possibilities.up_possible(mv))
  {
    my_state.set_cell(mv.top, true);
    my_state.set_cell(mv.middle, false);
    my_state.set_cell(mv.bottom, false);
  }
  else
  {
    throw "do_up: Not possible!";
  }
  return my_state;
}

State Turn::do_down(Move mv)
{
  State my_state = this->show();
  if(this->possibilities.down_possible(mv))
  {
    my_state.set_cell(mv.top, false);
    my_state.set_cell(mv.middle, false);
    my_state.set_cell(mv.bottom, true);
  }
  else
  {
    throw "do_down: Not possible!";
  }
  return my_state;
}

State Turn::do_move(Move mv)
{
  State out;
  if(!this->possibilities.possible(mv))
  {
    throw "do_move: Not possible!";
  }
  else
  {
    if(this->possibilities.up_possible(mv)) out = this->do_up(mv);
    if(this->possibilities.down_possible(mv)) out = this->do_down(mv);
  }
  return out;
}

State Turn::make_move(void)
{
  Move mv = this->possibilities.top_move();
  this->possibilities.pop();
  return this->do_move(mv);
}

bool Turn::move_available(void)
{
  return this->number_of_moves_left() > 0;
}

size_t Turn::number_of_moves_left(void)
{
  return this->possibilities.number_of_moves();
}

bool Turn::solved(void)
{
  return this->show().complexity() == 1;
}
State Turn::show(void)
{
  return this->possibilities.show();
}

Turn Turn::go_to_the_next_turn(void)
{
  State new_state = this->make_move();
  Turn out(new_state);
  return out;
}

Move& Turn::top_move(void)
{
  return this->possibilities.top_move();
}

#endif // Turn_H_INCLUDED