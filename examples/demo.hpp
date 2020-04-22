#pragma once

#include <iostream>

#include "mobius.hpp"

namespace demo
{

using logic_t = std::vector<std::string>; // Swap this out for whatever type your logic object is

// Forward declare your states
class enhanced_state;
class enhanced_state_two;

// Define your states
class enhanced_state : public mobius::state
{
private:
  std::shared_ptr<mobius::enhanced_engine<logic_t>> state_engine_;

public:
  enhanced_state(std::shared_ptr<mobius::enhanced_engine<logic_t>> engine);

  void enter();
  void handle_input(int ch);
  void restore();
  void exit();
};


class enhanced_state_two : public mobius::state
{
private:
  std::shared_ptr<mobius::enhanced_engine<logic_t>> state_engine_;

public:
  enhanced_state_two(std::shared_ptr<mobius::enhanced_engine<logic_t>> engine);

  void enter();
  void handle_input(int ch);
  void restore();
  void exit();
};




// Implement your states
enhanced_state::enhanced_state(std::shared_ptr<mobius::enhanced_engine<logic_t>> engine)
{
  this->state_engine_ = engine;
}

void enhanced_state::enter()
{
  std::cout << "Entered enhanced_state!\n";
}

void enhanced_state::handle_input(int ch)
{
  switch (ch)
  {
    case 'q':
    case 'Q':
      std::cout << "OK BYEEEE!\n";
      this->state_engine_->pop();
      break;
    case 'p':
    case 'P':
      std::cout << "Pushing new state!\n";
      this->state_engine_->push<demo::enhanced_state_two>();
      break;
    default:
      std::cout << "Whatever\n";
  }
}

void enhanced_state::restore()
{
  std::cout << "Restored enhanced_state!\n";
}

void enhanced_state::exit()
{
  std::cout << "Left enhanced_state!\n";
}


enhanced_state_two::enhanced_state_two(std::shared_ptr<mobius::enhanced_engine<logic_t>> engine)
{
  this->state_engine_ = engine;
}

void enhanced_state_two::enter()
{
  std::cout << "Entered enhanced_state_two!\n";
}

void enhanced_state_two::handle_input(int ch)
{
  switch (ch)
  {
    case 'q':
    case 'Q':
      std::cout << "OK BYEEEE! enhanced_state_two\n";
      this->state_engine_->pop();
      break;
    case 'p':
    case 'P':
      std::cout << "Pushing new state! enhanced_state_two\n";
      break;
    default:
      std::cout << "Whatever enhanced_state_two\n";
  }
}

void enhanced_state_two::restore()
{
  std::cout << "Restored enhanced_state_two!\n";
}

void enhanced_state_two::exit()
{
  std::cout << "Left enhanced_state_two!\n";
}





// Vanilla states

class state_one : public mobius::state
{
private:
  std::shared_ptr<mobius::engine> state_engine_;

public:
  state_one(std::shared_ptr<mobius::engine> engine);

  void enter();
  void handle_input(int ch);
  void restore();
  void exit();
};

state_one::state_one(std::shared_ptr<mobius::engine> engine)
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
private:
  std::shared_ptr<mobius::engine> state_engine_;

public:
  state_two(std::shared_ptr<mobius::engine> engine);

  void enter();
  void handle_input(int ch);
  void restore();
  void exit();
};

state_two::state_two(std::shared_ptr<mobius::engine> engine)
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
