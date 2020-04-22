#pragma once

#include <vector>
#include <memory>

#include "state_engine.hpp"

namespace mobius
{

class state
{
public:
  virtual void enter() = 0;
  virtual void handle_input(int ch) = 0;
  virtual void restore() = 0;
  virtual void exit() = 0;
};

} // namespace mobius
