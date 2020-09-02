#ifndef PBTRIPLES_H_INCLUDED
#define PBTRIPLES_H_INCLUDED

#include"pbrows.h"
#include <vector>

struct triple
{
  size_t top;
  size_t middle;
  size_t bottom;
};

template <size_t SIZE>
class PBTriples
{
public:
  PBTriples(void);
  static std::vector<triple> make_triples(void)
  {
    PBRows<SIZE> pbr;
    std::vector<triple> out;
    std::vector<std::vector<size_t> > slants = pbr.rows();
    for(std::vector<size_t> sl : slants)
    {
      for(size_t index = 0; index < sl.size() - 2; ++index)
      {
        triple t;
        t.top = sl[index];
        t.middle = sl[index + 1];
        t.bottom = sl[index + 2];
        out.push_back(t);
      }
    }
    return out;
  }

};

template <size_t SIZE>
PBTriples<SIZE>::PBTriples(void)
{
  /*Do Nothing*/
}



#endif // PBTRIPLES_H_INCLUDED