#ifndef __MY_BLOCKCHAIN_BLOCKCHAIN_H__
#define __MY_BLOCKCHAIN_BLOCKCHAIN_H__
#include "Block.hpp"
#include "json.hpp"
#include <vector>
using json = nlohmann::json;
namespace my_blockchain {
class Blockchain {
public:
  /**
   * @brief Construct a new Blockchain object
   *
   * @param difficulty Mining difficulty.
   */
  Blockchain(uint64_t difficulty = 6);
  /**
   * @brief Add a new block to the blockchain.
   *
   * @param block The new block to be added.
   */
  void AddBlock(Block block);
  /**
   * @brief Set the Difficulty object
   *
//    * @param difficulty New mining difficulty.
   */
  void SetDifficulty(uint64_t difficulty);
  /**
   * @brief Jsonify the block chain and print it to the cout.
   *
   */
  void JSON() const;
  /**
   * @brief Check if the Blockchain is valid or not
   *
   * @return true Valid.
   * @return false Not Valid.
   */
  bool IsValid() const;

private:
  uint64_t difficulty_;
  std::vector<Block> chain_;
  Block GetLastBlock_() const;
};
} // namespace my_blockchain

#endif // __MY_BLOCKCHAIN_BLOCKCHAIN_H__