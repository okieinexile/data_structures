#ifndef MOVE_POSSIBILITIES_H_INCLUDED
#define MOVE_POSSIBILITIES_H_INCLUDED

#include"moves.h"
#include"states.h"
#include"path.h"

struct Pegs
{
  bool top, middle, bottom;
};

class MovePossibilities 
{
  private:
    State state; 
    //std::vector<Move> moves;
    Path moves;

  public:
    MovePossibilities(void);
    MovePossibilities(State p_state);
    Pegs peek(Move mv);
    bool up_possible(Move mv);
    bool down_possible(Move mv);
    bool possible(Move mv);
    void find_moves(void);
    Move& top_move(void);
    void pop(void);
    size_t number_of_moves(void);
    size_t pegs_left(void);
    bool moves_are_available(void);
    State show(void);
};

MovePossibilities::MovePossibilities(void){/* Do nothing */}

MovePossibilities::MovePossibilities(State p_state)
{
  this->state = p_state;
  this->find_moves();
}

Pegs MovePossibilities::peek(Move mv)
{
  Pegs out;
  out.top = this->state.read_cell(mv.top);
  out.middle = this->state.read_cell(mv.middle);
  out.bottom = this->state.read_cell(mv.bottom);
  return out;
}

bool MovePossibilities::up_possible(Move mv)
{
  Pegs pk = this->peek(mv);
  return (!pk.top) && pk.middle && pk.bottom; 
}

bool MovePossibilities::down_possible(Move mv)
{
  Pegs pk = this->peek(mv);
  return pk.top && pk.middle && (!pk.bottom); 
}

bool MovePossibilities::possible(Move mv)
{
  return this->up_possible(mv) || this->down_possible(mv);
}

void MovePossibilities::find_moves(void)
{
  for(Move mv : Move::all_moves())
  {
    if(this->possible(mv)) this->moves.push(mv);
  }
}

Move& MovePossibilities::top_move(void)
{
  return this->moves.top();
}

void MovePossibilities::pop(void)
{
  this->moves.pop();
}

size_t MovePossibilities::number_of_moves(void)
{
  return this->moves.size();
}

size_t MovePossibilities::pegs_left(void)
{
  return this->state.complexity();
}

bool MovePossibilities::moves_are_available(void)
{
  return this->number_of_moves() > 0;
}

State MovePossibilities::show(void)
{
  return this->state;
}

#endif