# Mobius <img align="right" src="https://img.icons8.com/dotty/80/000000/infinity.png">
A very basic Finite State Machine with infinite potential, Mobius is a header-only library compatible with C++14 and above.

## Installation

You can either clone the repo and pop the include folder into your project, or use git submodules. For example:

```shell
git submodule add git@github.com:rufus-stone/mobius.git

git submodule update --init --recursive
```

Then add the following to your CMakeLists.txt file:

```cmake
include_directories(mobius/include)
```

Now you're ready to start building your state machine.

## Usage

Once the library is installed, usage is very straight forward. First, you need to `#include` the Mobius header in your code:

```cpp
#include "mobius.hpp"
```

Second, you'll need to create some classes that inherit from `mobius::state` - these will be your custom states that the engine will operate on. You need to implement four functions: `enter()`, `handle_input(int ch)`, `restore()`, and `exit()`. For example:

```cpp
class example_state : public mobius::state
{
public:
  example_state(std::shared_ptr<mobius::state_engine> engine);

  void enter();
  void handle_input(int ch);
  void restore();
  void exit();
};

example_state::example_state(std::shared_ptr<mobius::state_engine> engine)
{
  // Your constructor should always take a pointer to the state engine, in order to allow this state to push/pop other states to/from the engine
  this->state_engine_ = engine;
}

void example_state::enter()
{
  // This is called when a state is first pushed onto the engine stack
  // This is a good place to handle any calls to interface drawing code, etc.
  std::cout << "Entered the state!\n";
}

void example_state::handle_input(int ch)
{
  // This is where you want to handle any user input events, e.g. keyboard presses
  // You could push a new state into the engine here if a given input occurs, or pop the current state off the stack
  std::cout << "Handling input!\n";
}

void example_state::restore()
{
  // This is called when a state that was previously active but had been made inactive is brought back to the fore
  std::cout << "Restored the state!\n";
}

void example_state::exit()
{
  // Put any cleanup code here
  std::cout << "Left the state!\n";
}
```

The `mobius::state` class also provides a `get_engine()` method which returns a raw pointer to the engine - you can use this to interact with the engine from within a state, e.g. to push or pop new states from within the `handle_input()` method.

- Todo: Figure out how to use std::shared_ptr instead of raw pointers here. This is problematic due to the way shared_from_this() works with derived classes

Once you've created your new state subclasses, you'll need an engine to drive them. Mobius provides two flavours of state engine - the vanilla `mobius::engine` that simply handles user input and state changes, and the tastier `mobius::enhanced_engine` that will internally create an object of your choosing that you can use to handle any business logic requirements. Both varieties expose the same simple interface: a templated `push<>()` method which you use to push a new state onto the stack, a `pop()` method to remove the top-most state from the stack, a `handle_input(int ch)` method that calls the corresponding `handle_input(int ch)` method for the currently active state, and an `empty()` method that returns a `bool` indicating if the internal stack of states is empty.

Usage is very simple:


```cpp
// First, generate a new state engine using the factory functions mobius::new_engine() for a vanilla state engine, or mobius::new_enhanced_engine<>() for a tastier state engine.
// Both functions return a std::shared_ptr to your new state engine
auto engine = mobius::new_engine(); // Get a vanilla engine

// Push the first state into the engine - this will call the given stat's enter() method, and this will become the active state
// This templated function will accept any class of state as long as it is derived from the mobius::state base class
engine->push<example_state>();

// Handle some user input event - this should probably go inside your main event loop
engine->handle_input('q');

// Pop the current state off the top of the stack - this will call the state's exit() method
engine->pop();

// If we want an enhanced engine with more complex functionality, you can call mobius::new_enhanced_engine<>() instead
struct complex_game_logic {}; // Pretend this is your complex game logic
auto fake_game_engine = mobius::new_enhanced_engine<complex_game_logic>();

// To access that logic object, call the logic() method
std::cout << fake_game_engine->logic().player_health << '\n'; // Assuming the complex_game_logic object has a member called player_health, this is how you could access it

// You can also pass values that will be used to construct the business logic object
auto another_example = mobius::new_enhanced_engine<std::vector<std::string>>("One", "Two"); // This creates a new std::vector<std::string> populated with the values provided.

// This logic object is modifiable like this:
another_example->logic().push_back("New entry in the vector");

```

That's about it.

- Todo: Generalise the `handle_input()` method to accept inputs other than just an int/char






<a href="https://icons8.com/icon/78039/infinity">Infinity icon by Icons8</a>
