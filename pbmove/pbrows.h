#ifndef PBROWS_H_INCLUDED
#define PBROWS_H_INCLUDED

#include <vector>
#include"pbslant.h"
#include"../math/math.h"

template <size_t SIZE>
class PBRows 
{
public:
 std::vector<pbrow> pegboard_rows;
 PBRows(void);
 void make_rows(void);
 void make_left(void);
 void make_right(void);
 void make_straight(void);
 std::vector<pbrow> rows(void);
};

template <size_t SIZE>
PBRows<SIZE>::PBRows(void)
{
  this->make_rows();
}

template <size_t SIZE>
void PBRows<SIZE>::make_rows(void)
{
  this->make_left();
  this->make_right();
  this->make_straight();
}

template <size_t SIZE>
void PBRows<SIZE>::make_left(void)
{
  PBSlant<SIZE> pbs(0,1);
  pbrow myrow = pbs.slant();
  while(!(myrow.size() < 3))
  {
    this->pegboard_rows.push_back(myrow);
    myrow = pbs.left_translate(myrow);
  }
}

template <size_t SIZE>
void PBRows<SIZE>::make_right(void)
{
  PBSlant<SIZE> pbs(0, 2);
  pbrow myrow = pbs.slant();
  while(!(myrow.size() < 3))
  {
    this->pegboard_rows.push_back(myrow);
    myrow = pbs.right_translate(myrow);
  }
}

template <size_t SIZE>
void PBRows<SIZE>::make_straight(void)
{
  PBSlant<SIZE> pbs(SIZE - last_row(SIZE), 0);
  pbrow myrow = pbs.slant();
  while(!(myrow.size() < 3))
  {
    this->pegboard_rows.push_back(myrow);
    myrow = pbs.straight_translate(myrow);
  }
}

template <size_t SIZE>
std::vector<pbrow> PBRows<SIZE>::rows(void)
{
  return this->pegboard_rows;
}

#endif // PBROWS_H_INCLUDED