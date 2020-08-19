#ifndef MACHINE_H_INCLUDED
#define MACHINE_H_INCLUDED

#include <vector>

template <typename ALPHABET, typename STATE>
class Machine 
{
  public:
    std::vector<ALPHABET> sigma;
    std::vector<STATE> states;
    STATE initial;
    STATE delta(STATE state, ALPHABET letter);
    Machine(STATE s0);
};

template <typename ALPHABET, typename STATE>
Machine::Machine(STATE s0)
{
  this->initial = s0;
  this->states.push_back(s0);
}

#endif //MACHINE_H_INCLUDED