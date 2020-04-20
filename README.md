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

Once you've created your new state subclasses, you can use them like this:


```cpp
// First, generate a new state engine using the factory function mobius::new_state_engine(). This will return a std::shared_ptr to the engine
auto engine = mobius::new_state_engine();

// Push the first state into the engine - this will call the given stat's enter() method, and this will become the active state
engine->push(std::make_unique<example_state>(engine));

// Handle some user input event - this should probably go inside your main event loop
engine->handle_input('q');

// Pop the current state off the top of the stack - this will call the state's exit() method
engine->pop();

```

That's about it.

- TODO: Generalise the `handle_input()` method to accept inputs other than just an int/char






<a href="https://icons8.com/icon/78039/infinity">Infinity icon by Icons8</a>
