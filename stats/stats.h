#ifndef STATS_H_INCLUDED
#define STATS_H_INCLUDED

#include"../final_states/final_states.h"
#include"../pbstream/pbstream.h"
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include"../pbnode/pbnode.h"

template <pb_code SIZE, pb_code CELL>
class Stats 
{
private:
  std::string filename;
  FinalStates<SIZE,CELL> final_states;
  std::ofstream outfile;
  std::map<pb_code,int> distribution;
  void make_states(void);
  void make_distribution(void);
public:
  Stats(const std::string& filename);
  void report(void);
  void save(void);
};

template <pb_code SIZE, pb_code CELL>
Stats<SIZE,CELL>::Stats(const std::string& myfilename)
{
  FinalStates<SIZE,CELL> fs;
  this->final_states = fs;
  this->filename = myfilename;
}

template <pb_code SIZE, pb_code CELL>
void Stats<SIZE,CELL>::make_states(void)
{
  std::cout << "This may take some time." <<std::endl;
  this->final_states.find_final_states();
}

template <pb_code SIZE, pb_code CELL>
void Stats<SIZE,CELL>::report(void)
{
  this->make_states();
  this->make_distribution();
  this->save();
}

template <pb_code SIZE, pb_code CELL>
void Stats<SIZE,CELL>::make_distribution(void)
{
  for(PBNode node : this->final_states.states)
  {
    ++this->distribution[node.board.complexity()];
  }
}

template <pb_code SIZE, pb_code CELL>
void Stats<SIZE,CELL>::save(void)
{
  this->outfile.open(this->filename);
  outfile << "Size = " << SIZE 
          << " Cell = " << CELL << std::endl;  
  for(std::pair<pb_code,int> data: distribution)
  {
    outfile<<"Complexity = " << data.first 
             <<" Frequency = " << data.second
             << std::endl;
  }  
  this->outfile.close();
}

#endif //  STATS_H_INCLUDED