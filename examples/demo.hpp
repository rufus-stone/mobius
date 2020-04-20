#pragma once

#include <iostream>

#include "mobius.hpp"

namespace demo
{

class state_one : public mobius::state
{
public:
  state_one(std::shared_ptr<mobius::state_engine> engine);

  void enter();
  void handle_input(int ch);
  void restore();
  void exit();
};

state_one::state_one(std::shared_ptr<mobius::state_engine> engine)
{
  this->state_engine_ = engine;
}

void state_one::enter()
{
  std::cout << "Entered State One!\n";
}

void state_one::handle_input(int ch)
{
  std::cout << "Handling input for State One!\n";
}

void state_one::restore()
{
  std::cout << "Restored State One!\n";
}

void state_one::exit()
{
  std::cout << "Left State One!\n";
}



class state_two : public mobius::state
{
public:
  state_two(std::shared_ptr<mobius::state_engine> engine);

  void enter();
  void handle_input(int ch);
  void restore();
  void exit();
};

state_two::state_two(std::shared_ptr<mobius::state_engine> engine)
{
  this->state_engine_ = engine;
}

void state_two::enter()
{
  std::cout << "Entered State Two!\n";
}

void state_two::handle_input(int ch)
{
  std::cout << "Handling input for State Two!\n";
}

void state_two::restore()
{
  std::cout << "Restored State Two!\n";
}

void state_two::exit()
{
  std::cout << "Left State Two!\n";
}

} // namespace demo
