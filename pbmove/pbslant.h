#ifndef PBSLANT_H_INCLUDED
#define PBSLANT_H_INCLUDED

#include <vector>

typedef std::vector<pb_code> pbrow;

template <pb_code SIZE>
class PBSlant 
{
private:
  pbrow entries;
public:
  PBSlant(pb_code peghole0, pb_code diff0);
  pbrow translate(pbrow myslant, int c); 
  pbrow left_translate(pbrow myslant);
  pbrow right_translate(pbrow myslant);
  pbrow straight_translate(pbrow myslant);
  pbrow slant(void);
};

template <pb_code SIZE>
PBSlant<SIZE>::PBSlant(pb_code peghole0, pb_code diff0)
{
  pb_code peghole = peghole0;
  pb_code diff = diff0;
  while(peghole < SIZE)
  {
    this->entries.push_back(peghole);
    if(diff == 0)
    {
      ++peghole;
    }
    else
    {
      peghole += diff;
      ++diff;
    }
  }
}

template <pb_code SIZE>
pbrow PBSlant<SIZE>::translate(pbrow myslant, int c)
{
  pbrow out;
  for(pb_code index = 1; index < myslant.size(); ++index) out.push_back(myslant[index] + c);
  return out;
}

template <pb_code SIZE>
pbrow PBSlant<SIZE>::left_translate(pbrow myslant)
{
  return translate(myslant,1);
}

template <pb_code SIZE>
pbrow PBSlant<SIZE>::right_translate(pbrow myslant)
{
  return translate(myslant, -1);
}

template <pb_code SIZE>
pbrow PBSlant<SIZE>::straight_translate(pbrow myslant)
{
  pbrow out;
  for(pb_code index = 1; index < myslant.size(); ++index)
  {
    out.push_back(myslant[index] - myslant.size());
  }
  return out; 
}

template <pb_code SIZE>
pbrow PBSlant<SIZE>::slant(void)
{
  return this->entries;
}
#endif // PBSLANT_H_INCLUDED