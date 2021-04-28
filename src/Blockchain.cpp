#include "Blockchain.hpp"
namespace my_blockchain {
Blockchain::Blockchain(uint64_t difficulty) : difficulty_(difficulty) {
  Block first_block(0, "First Block!");
  first_block.MineBlock(difficulty_);
  chain_.push_back(first_block);
}

void Blockchain::AddBlock(Block block) {
  block.PrevHash = GetLastBlock_().GetHash();
  block.MineBlock(difficulty_);
  chain_.push_back(block);
}

Block Blockchain::GetLastBlock_() const { return chain_.back(); }

void Blockchain::SetDifficulty(uint64_t difficulty) {
  difficulty_ = difficulty;
}

void Blockchain::JSON() const {
  json j;
  for (const auto block : chain_) {
    auto time = block.GetTime();
    j["block_" + std::to_string(block.GetId())] = {
        {"hash", block.GetHash()},
        {"previous_hash", block.PrevHash},
        {"data", block.GetData()},
        {"time", std::ctime(&time)}};
  }
  std::cout << j.dump(4) << std::endl;
}

} // namespace my_blockchain