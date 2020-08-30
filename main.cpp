#include <iostream>
#include <fstream>
#include"peg_machine/peg_board_play.h"
#include"peg_machine/reachable_states.h"
#include"peg_machine/peg_board_output.h"
#include <map>


int main() 
{
  PegBoardPlay pbp;
  ReachableStates rs(pbp);
  std::set<PegBoardPlay> final_set;
  std::map<int,size_t> stats;
  rs.find_all_final_states();
  final_set = rs.final();
  for(PegBoardPlay pb : final_set)
  {
    //std::cout << pb << std::endl;
    ++stats[pb.complexity()];
  }
  std::ofstream out_file("stat_file.txt");
  out_file << rs.number_final_states() << std::endl;
  out_file << rs.number_of_ways() << std::endl;
  for(std::pair<int,size_t> st : stats)
  {
    out_file << "complexity = " << st.first 
              << " frequency = " << st.second << std::endl;
  }
  out_file.close();
  return 0; 
}