#pragma once

#include <vector>
#include <memory>

#include "state.hpp"

namespace mobius
{

// Forward declarations
////////////////////////////////////////////////////////////////
class state;

// Definitions
////////////////////////////////////////////////////////////////
class state_engine
{
private:
  std::vector<std::unique_ptr<state>> states_;

public:
  void handle_input(int ch);
  void push(std::unique_ptr<state> state_ptr);
  void pop();
  
  bool empty();
};

// Implementations
////////////////////////////////////////////////////////////////
void state_engine::push(std::unique_ptr<state> state_ptr)
{
  state_ptr->enter();

  this->states_.push_back(std::move(state_ptr));
}

////////////////////////////////////////////////////////////////
void state_engine::pop()
{
  if (!this->states_.empty())
  {
    this->states_.back()->exit();
    this->states_.pop_back();

    // Restore the previous state
    if (!this->states_.empty())
    {
      this->states_.back()->restore();
    }
  }
}

////////////////////////////////////////////////////////////////
void state_engine::handle_input(int ch)
{
  if (!this->states_.empty())
  {
    this->states_.back()->handle_input(ch);
  }
}

bool state_engine::empty()
{
  return this->states_.empty();
}


} // namespace mobius
