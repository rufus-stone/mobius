#pragma once

#include <vector>
#include <memory>

#include "state_engine.hpp"

namespace mobius
{

// Forward declarations
////////////////////////////////////////////////////////////////
class state_engine;

// Definitions
////////////////////////////////////////////////////////////////
class state
{
public:
  virtual void enter() = 0;
  virtual void handle_input(int ch) = 0;
  virtual void restore() = 0;
  virtual void exit() = 0;

protected:
  std::shared_ptr<state_engine> state_engine_;
};

} // namespace mobius
