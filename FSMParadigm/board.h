#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

class Board 
{
  public:
    size_t rank;
    std::vector<bool> cells;

    Board(void);
    Board(size_t p_rank);
    size_t size(void);
    void push(bool item);
    void pop(void);
    bool top(void);
    bool read_cell(size_t index);
    void set_cell(size_t index, bool value);
    size_t complexity(void);
};

Board::Board(void){/* Do Nothing */}

Board::Board(size_t p_rank)
{
  this->rank = p_rank;
}

size_t Board::size(void)
{
  return this->rank * (this->rank + 1) / 2;
}

void Board::push(bool item)
{
  this->cells.push_back(item);
}

void Board::pop(void)
{
  this->cells.pop_back();
}

bool Board::top(void)
{
  return this->cells.back();
}

bool Board::read_cell(size_t index)
{
  return this->cells[index];
}

void Board::set_cell(size_t index, bool value)
{
  this->cells[index] = value;
}

size_t Board::complexity(void)
{
  size_t out = 0;
  for(size_t i = 0; i < this->size(); ++i)
  {
    if(this->read_cell(i)) ++out;
  }
  return out;
}

#endif