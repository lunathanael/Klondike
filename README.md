# Turing Machine in C++
This project implements a game of Klondike in C++. It's designed to provide a practical and flexible foundation for simulating the game with customizable parameters with a simple AI implemented. 

## Features
**Customizable Settings**: Easily modifiable game options\
**CLI**: User friendly command line interface with a help menu.\
**Rudimentary AI**: Employs a basic AI based on heuristics to attempt to solve the game.\
**Fast and Efficient**: Efficient code allows rapid game simulation with AI to calculate winrate.

## Getting Started
### Prerequisites
  - C++ Compiler
  - Basic understanding of the game of Klondike.

### Installation
Clone the repository to your local machine:

```bash
git clone https://github.com/lunathanael/Klondike.git
```

### Usage
  1. Modify relevant options in `types.h`.
  2. Navigate to the direction and build with `make release`.
  3. Run `Klonedike.exe` via the terminal, and use `help` to access commands.


## Code Examples
```c++
// types.h
#define NUMBER_OF_DECKS 1
#define NUMBER_OF_PILES 7

#define NUMBER_OF_SUITS 4
#define CARDS_IN_SUIT 13
...
```

<img width="488" alt="image" src="https://github.com/lunathanael/Klondike/assets/68858103/f206b1f7-150e-4165-89b5-7903d67a18a7">

## Contributing
Contributions to enhance the functionality or efficiency of the Klondike Solitaire game or AI are welcome

### License
This project is licensed under the MIT License - see the LICENSE.md file for details.

### Contact
Nathanael Lu - info@lunathanael.dev

Project [Link](https://github.com/lunathanael/Klondike)
