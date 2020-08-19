#ifndef PATH_H_INCLUDED
#define PATH_H_INCLUDED

#include <vector>
#include"moves.h"

class Path 
{
  public:
  std::vector<Move> moves;

  Path(void);
  void push(Move& mv);
  void pop(void);
  Move& top(void);
  size_t size(void);
};

std::ostream& operator<<(std::ostream& ost, Path my_path);

Path::Path(void){/*Do Nothing*/}

void Path::push(Move& mv)
{
  this->moves.push_back(mv);
}

void Path::pop(void)
{
  this->moves.pop_back();
}

Move& Path::top(void)
{
  return this->moves.back();
}

size_t Path::size(void)
{
  return this->moves.size();
}

std::ostream& operator<<(std::ostream& ost, Path my_path)
{
  for(size_t i = 0;i < my_path.size(); ++i)
  {
    ost << my_path.moves[i] << std::endl;
  }
  return ost;
}

#endif