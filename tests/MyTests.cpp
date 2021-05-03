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
  bc.AddTransaction(Transaction("", "test", 6.001));
  bc.AddBlock("test_wallet");
  bc.AddTransaction(Transaction("test", "test_wallet", 6.001));
  bc.AddBlock("test");
  REQUIRE(bc.GetBalance("test") == 0);
  REQUIRE(bc.GetBalance("test_wallet") == 7.001);
}

TEST_CASE("Sign a Transaction With correct Key", "[Transaction]") {
  CryptoPP::AutoSeededRandomPool prng;
  ECDSA<ECP, CryptoPP::SHA256>::PrivateKey privateKey;
  privateKey.Initialize(prng, ASN1::secp256k1());
  std::string public_key = GetPublicKey(privateKey);
  Transaction tr(public_key, "essam", 0.5);
  std::cout << public_key << std::endl;
  REQUIRE(tr.SignTransaction(privateKey));
}

TEST_CASE("Sign a Transaction With wrong Key", "[Transaction]") {
  CryptoPP::AutoSeededRandomPool prng;
  ECDSA<ECP, CryptoPP::SHA256>::PrivateKey privateKey;
  privateKey.Initialize(prng, ASN1::secp256k1());
  std::string public_key = GetPublicKey(privateKey);
  public_key = "";
  Transaction tr(public_key, "essam", 0.5);
  std::cout << public_key << std::endl;
  REQUIRE_FALSE(tr.SignTransaction(privateKey));
}