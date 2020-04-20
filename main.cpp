#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "mobius.hpp"

#include "examples/demo.hpp"

int main()
{
  // Create a new state engine
  auto engine = mobius::new_state_engine();

  // Push an example state to the top of the stack
  engine->push(std::make_unique<demo::state_one>(engine));

  // Handle some input event against the state at the top of the state (in this case state_one)
  engine->handle_input('q');

  // Push a new state to the top of the stack
  engine->push(std::make_unique<demo::state_two>(engine));

  // Handle some input event against the state at the top of the state (in this case state_two)
  engine->handle_input('a');

  // Pop the top-most state from the stack. This will restore the previous state, if there is one (in this case, it will restore state_one)
  engine->pop();

  // Pop the next top-most state from the stack (in this case state_one)
  engine->pop();

  return 0;
}
