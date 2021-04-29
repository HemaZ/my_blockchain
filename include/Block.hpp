#ifndef MY_BLOCK_CHAIN__BLOCK_H__
#define MY_BLOCK_CHAIN__BLOCK_H__
#include "Transaction.hpp"
#include "sha256.hpp"
#include <iostream>
#include <sstream> // std::stringstream
#include <string>
#include <vector>
namespace my_blockchain {
/**
 * @brief
 *
 */
class Block {
public:
  /**
   * @brief Construct a new Block object
   *
   * @param index
   * @param data
   */
  Block(const std::vector<Transaction> &transactions);
  /**
   * @brief Set the Prev Hash object
   *
   * @param hash
   */
  void SetPrevHash(const std::string &hash);
  /**
   * @brief Get the Prev Hash object
   *
   * @return std::string
   */
  std::string GetPrevHash() const;
  /**
   * @brief Get the Hash object
   *
   * @return std::string
   */
  std::string GetHash() const;
  /**
   * @brief Get the Data object
   *
   * @return std::string
   */
  const std::vector<Transaction> &GeTransactions() const;
  /**
   * @brief Get the Time object
   *
   * @return time_t
   */
  time_t GetTime() const;
  /**
   * @brief Get the Id object
   *
   * @return uint64_t
   */
  uint64_t GetId() const;
  /**
   * @brief
   *
   * @param difficulty
   */
  void MineBlock(uint64_t difficulty);
  /**
   * @brief Calculate the block hash.
   *
   * @return std::string block's hash.
   */
  inline std::string CalculateHash() const {
    std::stringstream ss;
    ss << index_ << time_ << nonce_ << prev_hash_;
    for (const auto &transaction : transactions_) {
      ss << transaction.GetSender() << transaction.GetReceiver()
         << transaction.GetAmount();
    }
    return sha256(ss.str());
  }
  void SetIndex(uint64_t index);

private:
  std::string prev_hash_;
  uint64_t index_;
  int64_t nonce_;
  const std::vector<Transaction> transactions_;
  std::string hash_;
  time_t time_;
};
} // namespace my_blockchain
#endif // MY_BLOCK_CHAIN__BLOCK_H__