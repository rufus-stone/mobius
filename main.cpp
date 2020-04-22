#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "mobius.hpp"

#include "examples/demo.hpp"

int main()
{
  // Create a new vanilla state engine
  auto engine = mobius::new_engine();

  // Push an example state to the top of the stack
  engine->push<demo::state_one>();

  // Handle some input event against the state at the top of the state (in this case state_one)
  engine->handle_input('q');

  // Push a new state to the top of the stack
  engine->push<demo::state_two>();

  // Handle some input event against the state at the top of the state (in this case state_two)
  engine->handle_input('a');

  // Pop the top-most state from the stack. This will restore the previous state, if there is one (in this case, it will restore state_one)
  engine->pop();

  // Pop the next top-most state from the stack (in this case state_one)
  engine->pop();


  // Create an enhanced engine with a vector as it's business logic object
  auto game_engine = mobius::new_enhanced_engine<std::vector<std::string>>("one", "two");

  // We can interact with the internal logic object like this
  game_engine->logic().push_back("three");

  std::cout << "Internal logic vector now has size: " << game_engine->logic().size() << '\n'; // Internal logic vector now has size: 3

  game_engine->push<demo::enhanced_state>();

  game_engine->handle_input('p');
  game_engine->handle_input('a');
  game_engine->handle_input('q');

  return 0;
}
