#pragma once

#include <vector>
#include <memory>

#include "state_engine.hpp"

namespace mobius
{

// Forward declarations
////////////////////////////////////////////////////////////////
class engine;

// Definitions
////////////////////////////////////////////////////////////////
class state
{
protected:
  engine *state_engine_; // We should use a shared_ptr if I can figure out how!

public:
  virtual void enter() = 0;
  virtual void handle_input(int ch) = 0;
  virtual void restore() = 0;
  virtual void exit() = 0;

  // We can use this to interact with the state engine directly from within a given state
  engine* get_engine() const
  {
    return this->state_engine_;
  }
};

} // namespace mobius
