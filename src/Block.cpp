#include "Block.hpp"
namespace my_blockchain {
Block::Block(uint64_t index, const std::string &data)
    : index_(index), data_(data) {
  nonce_ = -1;
  time_ = time(nullptr);
}
std::string Block::GetHash() const { return hash_; }

std::string Block::GetPrevHash() const { return prev_hash_; }

void Block::SetPrevHash(const std::string &hash) { prev_hash_ = hash; }

void Block::MineBlock(uint64_t difficulty) {

  std::string difficulty_str = "";
  for (uint64_t i = 0; i < difficulty; i++) {
    difficulty_str += "0";
  }
  do {
    nonce_++;
    hash_ = CalculateHash();
  } while (hash_.substr(0, difficulty) != difficulty_str);

  std::cout << "Block Mined: " << hash_ << std::endl;
}

std::string Block::GetData() const { return data_; }
time_t Block::GetTime() const { return time_; }
uint64_t Block::GetId() const { return index_; }
} // namespace my_blockchain