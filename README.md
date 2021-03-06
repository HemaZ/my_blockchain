# My Blockchain

<p align="center">
  <img width="200" height="200" src="logo.png">
</p>

A simple C++ implementation of a Blockchain. Using mining as a proof of work.

## What it can do?

  - [x] Generate Private and Public (wallet address) keys.
  - [x] Create Transcations and sign them with your private key.
  - [x] Add the Transcations to the BlockChain.
  - [x] Mine for a new block and receive a mining reward.
  - [x] Change mining difficulty. 
  - [x] Get the balance of a certain wallet address.
  - [x] Validate the Blockchain. 
  - [x] Export the Blockchain in JSON format.
  - [ ] Anything else.

## How to build

* Crypto++ with CMake support.
    ```bash
    git clone https://github.com/weidai11/cryptopp.git
    cd cryptopp
    wget -O CMakeLists.txt https://raw.githubusercontent.com/noloader/cryptopp-cmake/master/CMakeLists.txt
    wget -O cryptopp-config.cmake https://raw.githubusercontent.com/noloader/cryptopp-cmake/master/cryptopp-config.cmake
    `mkdir build && cd build && cmake .. && sudo make install`
    ```
* My BLockchain
  
    `mkdir build && cd build && cmake .. && make`

## How to run

`cd build && ./main`

## How to use

```c++
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
}
```
## References 
[1] https://github.com/Savjee/SavjeeCoin
