#ifndef __MY_BLOCKCHAIN_BLOCKCHAIN_H__
#define __MY_BLOCKCHAIN_BLOCKCHAIN_H__
#include "Block.hpp"
#include "json.hpp"
#include "utils.hpp"
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
  Blockchain(uint64_t difficulty = 6, double reward = 10);
  /**
   * @brief Add a new block to the blockchain.
   *
   * @param block The new block to be added.
   */
  void AddBlock(const string &reward_address);
  /**
   * @brief Set the Difficulty object
   *
//    * @param difficulty New mining difficulty.
   */
  void SetDifficulty(uint64_t difficulty) { difficulty_ = difficulty; }
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
  /**
   * @brief Add new transaction to be processed.
   *
   * @param tr Transactino to be addded.
   * @return true Transaction is signed and added.
   * @return false Transaction not signed and couldn't be added.
   */
  bool AddTransaction(const Transaction &tr);
  /**
   * @brief Get the Balance of this wallet.
   *
   * @param address wallet address.
   * @return double total balance.
   */
  double GetBalance(const string &address);

private:
  uint64_t difficulty_;
  std::vector<Transaction> pending_transactions_;
  double mining_reward_;
  std::vector<Block> chain_;
  Block GetLastBlock_() const { return chain_.back(); }
};
} // namespace my_blockchain

#endif // __MY_BLOCKCHAIN_BLOCKCHAIN_H__