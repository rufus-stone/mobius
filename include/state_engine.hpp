#pragma once

#include <vector>
#include <memory>

#include "state.hpp"

namespace mobius
{

// Forward declarations
////////////////////////////////////////////////////////////////
class state;

// Vanilla state engine
////////////////////////////////////////////////////////////////
class engine : public std::enable_shared_from_this<engine>
{
protected:
  std::vector<std::unique_ptr<state>> states_;

public:
  template<typename state_t, typename = std::enable_if_t<std::is_base_of_v<mobius::state, state_t>>>
  void push()
  {
    auto state_ptr = std::make_unique<state_t>(this->shared_from_this());

    state_ptr->enter();

    this->states_.push_back(std::move(state_ptr));
  }

  void handle_input(int ch);
  void pop();
  bool empty();
};

////////////////////////////////////////////////////////////////
void engine::pop()
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
void engine::handle_input(int ch)
{
  if (!this->states_.empty())
  {
    this->states_.back()->handle_input(ch);
  }
}

bool engine::empty()
{
  return this->states_.empty();
}


// Enhanced state engine
////////////////////////////////////////////////////////////////
template<typename logic_t>
class enhanced_engine : public engine, public std::enable_shared_from_this<enhanced_engine<logic_t>>
{
protected:
  logic_t logic_;


public:
  enhanced_engine() = default;
  ~enhanced_engine() = default;

  enhanced_engine(logic_t logic_object) : logic_(logic_object)
  {
  }

  logic_t& logic()
  {
    return this->logic_;
  }
};

} // namespace mobius
