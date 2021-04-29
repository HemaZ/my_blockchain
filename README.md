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
 Blockchain my_blockchain(4,10); // 4 is the mining difficulty, 10 mining reward.

  my_blockchain.AddTransaction(Transaction("hema", "hema", 100));
  my_blockchain.AddTransaction(Transaction("hema", "ibrahim", 100));
  my_blockchain.AddTransaction(Transaction("ibrahim", "hema", 50));

  my_blockchain.AddBlock("hema"); // hema is the wallet address to receive the mining reward.

  my_blockchain.AddTransaction(Transaction("ibrahim", "hema", 50));
  my_blockchain.AddBlock("ibrahim");

  my_blockchain.JSON(); // This should print the following
}
```

Output should be something similar to this but with different hashes and times. 

```json
Block Mined: 00000b2db83f7ae09affb07f270420878a95a5c62f2f81e2d933473861c9a45e
Block Mined: 0000e17cbff67e89651a5b29058847069683267f76b01009bdd4eb6ef1ae7ab9
Block Mined: 0000516a38c44b2492c560536fc153902c6b82a85de9080374eeb073fbd4ca68
{
    "block_0": {
        "hash": "00000b2db83f7ae09affb07f270420878a95a5c62f2f81e2d933473861c9a45e",
        "previous_hash": "",
        "time": "Thu Apr 29 03:00:40 2021\n",
        "transactions": {
            "transaction_0": {
                "amount": 0.0,
                "receiver": "",
                "sender": ""
            }
        }
    },
    "block_1": {
        "hash": "0000e17cbff67e89651a5b29058847069683267f76b01009bdd4eb6ef1ae7ab9",
        "previous_hash": "00000b2db83f7ae09affb07f270420878a95a5c62f2f81e2d933473861c9a45e",
        "time": "Thu Apr 29 03:00:41 2021\n",
        "transactions": {
            "transaction_0": {
                "amount": 100.0,
                "receiver": "hema",
                "sender": "hema"
            },
            "transaction_1": {
                "amount": 100.0,
                "receiver": "ibrahim",
                "sender": "hema"
            },
            "transaction_2": {
                "amount": 50.0,
                "receiver": "hema",
                "sender": "ibrahim"
            }
        }
    },
    "block_2": {
        "hash": "0000516a38c44b2492c560536fc153902c6b82a85de9080374eeb073fbd4ca68",
        "previous_hash": "0000e17cbff67e89651a5b29058847069683267f76b01009bdd4eb6ef1ae7ab9",
        "time": "Thu Apr 29 03:00:42 2021\n",
        "transactions": {
            "transaction_0": {
                "amount": 10.0,
                "receiver": "hema",
                "sender": ""
            },
            "transaction_1": {
                "amount": 50.0,
                "receiver": "hema",
                "sender": "ibrahim"
            }
        }
    }
}
```