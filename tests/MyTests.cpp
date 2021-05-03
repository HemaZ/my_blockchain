#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Blockchain.hpp"
#include <limits>
#include <type_traits>
using namespace my_blockchain;
using namespace CryptoPP;
using CryptoPP::SecByteBlock;
TEST_CASE("Hash function is working", "[SHA256]") {
  std::string sha = sha256("Ibrahim Essam");
  CHECK(sha ==
        "ed8b5577ab0fb98d7af6c4f8ea9d01d7ae3309683ca75d9963b4e0ad6bcbc33a");
}

TEST_CASE("getting balance", "[Blockchain]") {
  Blockchain bc(3, 1);
  MyPrivateKey pk1 = GeneratePrivateKey();
  MyPrivateKey pk2 = GeneratePrivateKey();
  std::string puk1 = GetPublicKey(pk1);
  std::string puk2 = GetPublicKey(pk2);
  Transaction tr = Transaction(puk1, puk2, 6.00);
  tr.SignTransaction(pk1);
  CHECK(bc.AddTransaction(tr));
  bc.AddBlock(puk1);
  bc.AddBlock(puk2);
  REQUIRE(bc.GetBalance(puk1) == -5.00);
  REQUIRE(bc.GetBalance(puk2) == 6.00);
}

TEST_CASE("Sign a Transaction With correct Key", "[Transaction]") {
  MyPrivateKey privateKey = GeneratePrivateKey();
  std::string public_key = GetPublicKey(privateKey);
  Transaction tr(public_key, "essam", 0.5);
  std::cout << public_key << std::endl;
  REQUIRE(tr.SignTransaction(privateKey));
}

TEST_CASE("Sign a Transaction With wrong Key", "[Transaction]") {
  MyPrivateKey privateKey = GeneratePrivateKey();
  std::string public_key = GetPublicKey(privateKey);
  public_key = "";
  Transaction tr(public_key, "essam", 0.5);
  std::cout << public_key << std::endl;
  REQUIRE_FALSE(tr.SignTransaction(privateKey));
}