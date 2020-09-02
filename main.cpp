#include <iostream>
#include <fstream>
#include"final_states/final_states.h"
#include"pbstream/pbstream.h"
#include"math/math.h"


int main() 
{
  const size_t S = 15;
  const size_t C = 0;
  FinalStates<S,C> fs;
  fs.find_final_states();
  std::cout << fs.states.size() << std::endl;
  for(PBNode<S,C> pbn : fs.states)
  {
    std::cout << pbn.board << std::endl;
  }

  return 0; 
}