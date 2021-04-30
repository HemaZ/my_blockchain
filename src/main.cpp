#include "Blockchain.hpp"
using namespace my_blockchain;
int main(int argc, char const *argv[]) {
  Blockchain my_blockchain(4);

  my_blockchain.AddTransaction(Transaction("", "hema", 100));
  my_blockchain.AddTransaction(Transaction("hema", "ibrahim", 100));
  my_blockchain.AddTransaction(Transaction("ibrahim", "hema", 50));

  my_blockchain.AddBlock("hema");

  my_blockchain.AddTransaction(Transaction("ibrahim", "hema", 50));
  my_blockchain.AddBlock("ibrahim");

  std::cout << "ibrahim's Balance " << my_blockchain.GetBalance("ibrahim")
            << std::endl;
  std::cout << "hema's Balance " << my_blockchain.GetBalance("hema")
            << std::endl;

  my_blockchain.JSON();

  return 0;
}
