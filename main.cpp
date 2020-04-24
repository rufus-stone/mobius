#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "mobius.hpp"

#include "examples/demo.hpp"

int main()
{
  std::cout << "-----------------------------------------------\n";
  std::cout << "Demonstrating vanilla state engine operation...\n\n";

  // Create a new vanilla state engine
  auto engine = mobius::new_engine();

  // Push an example state to the top of the stack
  engine->push<demo::vanilla_state_one>();
  std::cout << "The size of state engine stack is now: " << engine->size() << '\n';;

  // Handle some input event against the state at the top of the state (in this case vanilla_state_one) - for example purposes, this will cause us to enter vanilla_state_two
  engine->handle_input('a');
  std::cout << "The size of state engine stack is now: " << engine->size() << '\n';

  // Handle some input event against the state at the top of the state (in this case vanilla_state_two) - for example purposes, this will pop vanilla_state_two and restore vanilla_state_one 
  engine->handle_input('a');
  std::cout << "The size of state engine stack is now: " << engine->size() << '\n';

  // Handle some input event against the state at the top of the state (in this case vanilla_state_one) - for example purposes, this will pop vanilla_state_one leaving the state stack empty
  engine->handle_input('q');
  std::cout << "The size of state engine stack is now: " << engine->size() << "\n\n\n";


  std::cout << "------------------------------------------------\n";
  std::cout << "Demonstrating enhanced state engine operation...\n\n";

  // Create an enhanced engine with a vector as it's business logic object, and initialize it with two strings
  auto game_engine = mobius::new_enhanced_engine<std::vector<std::string>>("one", "two");

  // We can interact with the internal logic object like this
  game_engine->logic().push_back("three");

  std::cout << "Internal logic vector now has size: " << game_engine->logic().size() << '\n'; // Internal logic vector now has size: 3

  // The rest of the functionality is the same as a vanilla state engine
  game_engine->push<demo::enhanced_state_one>();

  game_engine->handle_input('p');
  game_engine->handle_input('a');
  game_engine->handle_input('q');

  return 0;
}
