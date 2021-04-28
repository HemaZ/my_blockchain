#ifndef MY_BLOCK_CHAIN__BLOCK_H__
#define MY_BLOCK_CHAIN__BLOCK_H__
#include "sha256.hpp"
#include <cstdint>
#include <ctime>
#include <iostream>
#include <sstream> // std::stringstream
#include <string>
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
  Block(uint64_t index, const std::string &data);
  /**
   * @brief
   *
   */
  std::string PrevHash;
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
  std::string GetData() const;
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

private:
  uint64_t index_;
  int64_t nonce_;
  std::string data_;
  std::string hash_;
  time_t time_;
  inline std::string CalculateHash_() const;
};
} // namespace my_blockchain
#endif // MY_BLOCK_CHAIN__BLOCK_H__