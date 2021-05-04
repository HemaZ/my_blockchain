#include "Blockchain.hpp"
using namespace my_blockchain;
int main(int argc, char const *argv[]) {

  Blockchain my_blockchain(4, 100); // (Mining difficulty, Reward)
  // Generate new Private and Public keys.
  MyPrivateKey hema_pk = GeneratePrivateKey();
  std::string hema_wallet_address = GetPublicKey(hema_pk);
  std::cout << "Hema's Wallet Address " << hema_wallet_address << std::endl;
  // Create a new Transaction and sign it with the Private Key.
  Transaction tr(hema_wallet_address, "another_Wallet", 10);
  tr.SignTransaction(hema_pk);
  // Add the transaction to the Blockchain.
  my_blockchain.AddTransaction(tr);
  // Mine a new Block and send the mining reward to hema_wallet_address
  my_blockchain.AddBlock(hema_wallet_address);
  // Print the BlockChain in JSON Format.
  my_blockchain.JSON();

  return 0;
}
