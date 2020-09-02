#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

typedef unsigned long int pb_code;

pb_code last_row(pb_code mysize);


pb_code last_row(pb_code mysize)
{
  pb_code rows = 0;
  pb_code n = rows * (rows + 1) / 2;
  while( n < mysize)
  {
    ++rows;
    n = rows * (rows + 1) / 2;
  }
  return rows;
}



#endif // MATH_H_INCLUDED