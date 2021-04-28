#include "Blockchain.hpp"
using namespace my_blockchain;
int main(int argc, char const *argv[]) {
  Blockchain my_blockchain(2);

  std::cout << "Mining block 1..." << std::endl;
  my_blockchain.AddBlock(Block(1, "Block 1 Data"));

  std::cout << "Mining block 2..." << std::endl;
  my_blockchain.SetDifficulty(4);
  my_blockchain.AddBlock(Block(2, "Block 2 Data"));

  std::cout << "Mining block 3..." << std::endl;
  my_blockchain.SetDifficulty(4);
  my_blockchain.AddBlock(Block(3, "Block 3 Data"));

  my_blockchain.JSON();
  return 0;
}
