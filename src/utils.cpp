#include "utils.hpp"

namespace my_blockchain {
std::string GetPublicKey(const MyPrivateKey &private_key) {
  MyPublicKey public_key;
  private_key.MakePublicKey(public_key);
  std::string hex_key = "";
  // Use Save to DER encode the Subject Public Key Info (SPKI)
  public_key.Save(
      CryptoPP::HexEncoder(new CryptoPP::StringSink(hex_key)).Ref());

  return hex_key;
}
MyPublicKey GetPublicKey(const std::string &public_key) {
  MyPublicKey publicKey;
  publicKey.Load(
      CryptoPP::StringSource(public_key, true, new CryptoPP::HexDecoder())
          .Ref());
  return publicKey;
}

MyPrivateKey GeneratePrivateKey() {
  CryptoPP::AutoSeededRandomPool prng;
  CryptoPP::ECDSA<CryptoPP::ECP, CryptoPP::SHA256>::PrivateKey privateKey;
  privateKey.Initialize(prng, CryptoPP::ASN1::secp256k1());
  return privateKey;
}
} // namespace my_blockchain
