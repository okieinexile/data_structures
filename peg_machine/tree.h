#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <vector>
#include <map>
#include"peg_board_play.h"

const PegBoardPlay INFINITY(32767);

class Tree
{
  private:
    std::map<PegBoardPlay, PegBoardPlay> pred;
  public:
    Tree(void);
    void set_predecessor(PegBoardPlay& node, PegBoardPlay& pred);
    PegBoardPlay& predecessor(PegBoardPlay& node);
};

Tree::Tree(void)
{
  /*Do nothing*/ 
}

void Tree::set_predecessor(PegBoardPlay& node, PegBoardPlay& pred)
{
  this->pred.insert(std::pair<PegBoardPlay,PegBoardPlay>
                    (node, pred));
}

PegBoardPlay& Tree::predecessor(PegBoardPlay& node_code)
{
  return this->pred[node_code];
}
#endif // TREE_H_INCLUDED