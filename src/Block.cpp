#include "Block.hpp"
namespace my_blockchain {
Block::Block(const std::vector<Transaction> &transactions)
    : transactions_(transactions) {
  nonce_ = -1;
  time_ = time(nullptr);
}

std::string Block::CalculateHash() const {
  std::stringstream ss;
  ss << index_ << time_ << nonce_ << prev_hash_;
  for (const auto &transaction : transactions_) {
    ss << transaction.GetSender() << transaction.GetReceiver()
       << transaction.GetAmount();
  }
  return sha256(ss.str());
}

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

time_t Block::GetTime() const { return time_; }
uint64_t Block::GetId() const { return index_; }
void Block::SetIndex(uint64_t index) { index_ = index; }
const std::vector<Transaction> &Block::GeTransactions() const {
  return transactions_;
}
} // namespace my_blockchain