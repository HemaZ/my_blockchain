#include "Blockchain.hpp"
namespace my_blockchain {
Blockchain::Blockchain(uint64_t difficulty, double reward)
    : difficulty_(difficulty), mining_reward_(reward) {
  Block first_block({Transaction("", "", 0)});
  first_block.SetIndex(0);
  first_block.MineBlock(difficulty_);
  chain_.push_back(first_block);
}

void Blockchain::AddBlock(const string &reward_address) {
  Block block(pending_transactions_);
  block.SetIndex(chain_.size());
  block.SetPrevHash(GetLastBlock_().GetHash());
  block.MineBlock(difficulty_);
  chain_.push_back(block);
  pending_transactions_ = {Transaction("", reward_address, mining_reward_)};
}

Block Blockchain::GetLastBlock_() const { return chain_.back(); }

void Blockchain::SetDifficulty(uint64_t difficulty) {
  difficulty_ = difficulty;
}

void Blockchain::JSON() const {
  json j;
  for (const auto block : chain_) {
    json transactions;
    int32_t tr_id = 0;
    for (const auto &tr : block.GeTransactions()) {
      transactions["transaction_" + std::to_string(tr_id++)] = {
          {"sender", tr.GetSender()},
          {"receiver", tr.GetReceiver()},
          {"amount", tr.GetAmount()}};
    }
    auto time = block.GetTime();
    j["block_" + std::to_string(block.GetId())] = {
        {"hash", block.GetHash()},
        {"previous_hash", block.GetPrevHash()},
        {"time", std::ctime(&time)},
        {"transactions", transactions}};
  }
  std::cout << j.dump(4) << std::endl;
}

bool Blockchain::IsValid() const {
  for (auto ptr = chain_.begin() + 1; ptr != chain_.end(); ptr++) {
    auto current_block = *ptr;
    auto prev_block = *(ptr - 1);
    if (current_block.GetHash() != current_block.CalculateHash())
      return false;
    if (prev_block.GetHash() != current_block.GetPrevHash())
      return false;
  }
  return true;
}

void Blockchain::AddTransaction(const Transaction &tr) {
  pending_transactions_.push_back(tr);
}
} // namespace my_blockchain