#include <iostream>
#include <fstream>
#include"peg_machine/peg_board_play.h"
#include"peg_machine/reachable_states.h"
#include"peg_machine/peg_board_output.h"



int main() 
{
  PegBoardPlay pbp;
  ReachableStates rs(pbp);
  std::set<PegBoardPlay> final_set;
  std::set<PegBoardPlay>::iterator it;
  rs.make_tree();
  std::cout << rs.number_final_states() << std::endl;
  final_set = rs.final();
  std::ofstream data;
  data.open("final_states.txt");
  if(!data.fail())
  {
    for(PegBoardPlay p : final_set)
    {
      if(p.complexity() < 20)
      data << p << std::endl;
    }
  data.close();
  }

  return 0; 
}