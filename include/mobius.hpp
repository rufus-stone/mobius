#pragma once

#include <memory>

#include "state_engine.hpp"
#include "state.hpp"

namespace mobius
{

// Factory functions for getting a std::shared_ptr to a new state engine
////////////////////////////////////////////////////////////////
auto new_engine()
{
  return std::make_shared<engine>();
}

template<typename logic_t, typename ...params>
auto new_enhanced_engine(params&& ...p)
{
  return std::make_shared<enhanced_engine<logic_t>>(std::forward<logic_t>(logic_t{p...}));
}

} // namespace mobius
