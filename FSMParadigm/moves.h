#ifndef MOVES_H_INCLUDED
#define MOVES_H_INCLUDED

#include <vector>

class Move 
{
  public:
    Move(size_t top, size_t middle, size_t bottom)
    {
      this->top = top;
      this->middle = middle;
      this->bottom = bottom;
     }
    size_t top;
    size_t middle;
    size_t bottom;
    static std::vector<Move> all_moves(void)
    {
      std::vector<Move> out;
      const std::vector<std::vector<size_t> > TRIPLES({
              {0,1,3}, {1,3,6}, {3,6,10}, {2,4,7},{4,7,11}, {5,8,12},
              {0,2,5}, {2,5,9}, {5,9,14}, {1,4,8},{4,8,13}, {3,7,12},
              {3,4,5}, {6,7,8}, {7,8,9}, {10,11,12}, {11,12,13}, {12,13,14}
              });
      for(size_t i = 0; i < TRIPLES.size(); ++i)
      {
      Move mv(TRIPLES[i][0], TRIPLES[i][1], TRIPLES[i][2]);
      out.push_back(mv);
      }
      return out;
    }
};

std::ostream& operator<<(std::ostream& ost, Move mv);


std::ostream& operator<<(std::ostream& ost, Move mv)
{
  std::cout << "<" << mv.top << ", " 
                   << mv.middle << ", "
                   << mv.bottom << ">" << std::endl; 
  return ost;
}

#endif