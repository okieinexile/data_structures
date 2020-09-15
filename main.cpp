#include <iostream>
#include <fstream>
#include"final_states/final_states.h"
#include"pbstream/pbstream.h"
#include"stats/stats.h"


int main() 
{
  const size_t S = 15;
  const size_t C = 7;
  Stats<S,C> st("test_file_7.txt");
  st.report();


  return 0; 
}