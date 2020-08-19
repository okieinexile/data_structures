#ifndef ALGORITHM_H_INCLUDE
#define ALGORITHM_H_INCLUDE

#include <vector>
#include"states.h"
#include"turn.h"
#include"path.h"

class Algorithm 
{ 
  private:
    std::vector<Turn> turns;
    size_t count;
    Path path;

  public:
    Algorithm(void);
    Turn& current(void);
    void start(void);
    void make_move(void);
    bool can_go_back(void);
    void go_back(void);
    size_t pegs_left(void);
    State final(void);
    size_t iterations(void);
    Path winning_moves(void);
    
};

Algorithm::Algorithm(void)
{
  this->count = 0;
  Turn my_turn(5);
  this->turns.push_back(my_turn);
}

Turn& Algorithm::current(void)
{
  return turns.back();
}

void Algorithm::start(void)
{
  while(!this->current().solved())
  {
    ++this->count;
    if(this->current().move_available())
    {
      while(this->current().move_available())
      {
        this->make_move();
      }
    }
    else
    {
      if(!this->can_go_back()) break;
      else this->go_back();
    }
  }
}

void Algorithm::make_move(void)
{
  Turn new_turn = this->current().go_to_the_next_turn();
  this->path.push(this->current().top_move());
  this->turns.push_back(new_turn);
}

bool Algorithm::can_go_back(void)
{
  return this->turns.size() > 1;
}

void Algorithm::go_back(void)
{
  this->turns.pop_back();
  this->path.pop();
}

size_t Algorithm::pegs_left(void)
{
  return this->current().show().complexity();
}


State Algorithm::final(void)
{
  return this->current().show();
}

size_t Algorithm::iterations(void)
{
  return this->count;
}

Path Algorithm::winning_moves(void)
{
  return this->path;
}
#endif //ALGORITHM_H_INCLUDE