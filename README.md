# My Blockchain

A simple C++ implementation of a Blockchain.

## How to build

  `mkdir build && cd build && cmake .. && make`

## How to run

`cd build && ./main`

## How to use

```c++
#include "Blockchain.hpp"
using namespace my_blockchain;

int main(int argc, char const *argv[]) {
  Blockchain my_blockchain(2); // 2 is the initial mining difficulty. 

  std::cout << "Mining block 1..." << std::endl;
  my_blockchain.AddBlock(Block(1, "Block 1 Data")); // Adding new Block 

  std::cout << "Mining block 2..." << std::endl;
  my_blockchain.SetDifficulty(4); // Setting new mining difficulty. 
  my_blockchain.AddBlock(Block(2, "Block 2 Data"));

  my_blockchain.JSON(); // Print the Blockchain as Json.

  return 0;
}
```