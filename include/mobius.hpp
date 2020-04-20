#pragma once

#include <memory>

#include "state_engine.hpp"
#include "state.hpp"

namespace mobius
{

// Factory function for getting a std::shared_ptr to a new state engine
////////////////////////////////////////////////////////////////
auto new_state_engine()
{
  return std::make_shared<state_engine>();
}

} // namespace mobius