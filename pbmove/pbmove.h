#ifndef PBMOVE_H_INCLUDED
#define PBMOVE_H_INCLUDED

#include <vector>
//#include"generate_moves.h"
#include"pbtriples.h"

template <size_t SIZE>
class PBMove 
{
public:
  size_t top;
  size_t middle;
  size_t bottom;
  PBMove(size_t top, size_t middle, size_t bottom);
  static std::vector<PBMove> all_moves(void)
  {
    std::vector<PBMove> out;
    std::vector<triple> triples = PBTriples<SIZE>::make_triples();
    for(triple t : triples)
    {
      PBMove mv(t.top, t.middle, t.bottom);
      out.push_back(mv);
    }
    return out;
  }

};

template <size_t SIZE>
PBMove<SIZE>::PBMove(size_t top, size_t middle, size_t bottom)
{
  this->top = top;
  this->middle = middle;
  this->bottom = bottom;
}

#endif // PBMOVE_H_INCLUDED