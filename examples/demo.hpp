#pragma once

#include <iostream>

#include "mobius.hpp"

namespace demo
{

using logic_t = std::vector<std::string>; // Swap this out for whatever type your logic object is

// Forward declare your states
////////////////////////////////////////////////////////////////
class vanilla_state_one;
class vanilla_state_two;
class enhanced_state_one;
class enhanced_state_two;


// Define your states
////////////////////////////////////////////////////////////////
class vanilla_state_one : public mobius::state
{
private:
  std::shared_ptr<mobius::engine> state_engine_;

public:
  vanilla_state_one(std::shared_ptr<mobius::engine> engine) : state_engine_(engine) {}

  void enter();
  void handle_input(int ch);
  void restore();
  void exit();
};

////////////////////////////////////////////////////////////////
class vanilla_state_two : public mobius::state
{
private:
  std::shared_ptr<mobius::engine> state_engine_;

public:
  vanilla_state_two(std::shared_ptr<mobius::engine> engine) : state_engine_(engine) {}

  void enter();
  void handle_input(int ch);
  void restore();
  void exit();
};

////////////////////////////////////////////////////////////////
class enhanced_state_one : public mobius::state
{
private:
  std::shared_ptr<mobius::enhanced_engine<logic_t>> state_engine_;

public:
  enhanced_state_one(std::shared_ptr<mobius::enhanced_engine<logic_t>> engine) : state_engine_(engine) {}

  void enter();
  void handle_input(int ch);
  void restore();
  void exit();
};

////////////////////////////////////////////////////////////////
class enhanced_state_two : public mobius::state
{
private:
  std::shared_ptr<mobius::enhanced_engine<logic_t>> state_engine_;

public:
  enhanced_state_two(std::shared_ptr<mobius::enhanced_engine<logic_t>> engine) : state_engine_(engine) {}

  void enter();
  void handle_input(int ch);
  void restore();
  void exit();
};




// Implement your states
////////////////////////////////////////////////////////////////
void vanilla_state_one::enter()
{
  std::cout << "Entered vanilla_state_one!\n";
}

void vanilla_state_one::handle_input(int ch)
{
  std::cout << "Handling input for vanilla_state_one!\n";
  switch (ch)
  {
    case 'q':
    case 'Q':
      this->state_engine_->pop();
      break;

    default:
      this->state_engine_->push<demo::vanilla_state_two>();
      break;
  }
}

void vanilla_state_one::restore()
{
  std::cout << "Restored vanilla_state_one!\n";
}

void vanilla_state_one::exit()
{
  std::cout << "Left vanilla_state_one!\n";
}

////////////////////////////////////////////////////////////////
void vanilla_state_two::enter()
{
  std::cout << "Entered vanilla_state_two!\n";
}

void vanilla_state_two::handle_input(int ch)
{
  std::cout << "Handling input for vanilla_state_two!\n";
  this->state_engine_->pop();
}

void vanilla_state_two::restore()
{
  std::cout << "Restored vanilla_state_two!\n";
}

void vanilla_state_two::exit()
{
  std::cout << "Left vanilla_state_two!\n";
}

////////////////////////////////////////////////////////////////
void enhanced_state_one::enter()
{
  std::cout << "Entered enhanced_state_one!\n";
}

void enhanced_state_one::handle_input(int ch)
{
  std::cout << "Handling input for enhanced_state_one!\n";
  switch (ch)
  {
    case 'q':
    case 'Q':
      std::cout << "OK BYEEEE!\n";
      this->state_engine_->pop();
      break;
    case 'p':
    case 'P':
      this->state_engine_->push<demo::enhanced_state_two>();
      break;
  }
}

void enhanced_state_one::restore()
{
  std::cout << "Restored enhanced_state_one!\n";
}

void enhanced_state_one::exit()
{
  std::cout << "Left enhanced_state_one!\n";
}

////////////////////////////////////////////////////////////////
void enhanced_state_two::enter()
{
  std::cout << "Entered enhanced_state_two!\n";
}

void enhanced_state_two::handle_input(int ch)
{
  std::cout << "Handling input for enhanced_state_two!\n";
  this->state_engine_->pop();
}

void enhanced_state_two::restore()
{
  std::cout << "Restored enhanced_state_two!\n";
}

void enhanced_state_two::exit()
{
  std::cout << "Left enhanced_state_two!\n";
}

} // namespace demo
