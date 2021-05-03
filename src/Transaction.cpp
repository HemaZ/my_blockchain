#include "Transaction.hpp"
namespace my_blockchain {
bool Transaction::IsValid() const {
  if (sender_ == "")
    return true;
  if (signature_.size() == 0)
    return false;
  MyPublicKey publicKey = GetPublicKey(sender_);
  CryptoPP::ECDSA<CryptoPP::ECP, CryptoPP::SHA256>::Verifier verifier(
      publicKey);
  string message = GetHash();
  return verifier.VerifyMessage((const byte *)&message[0], message.size(),
                                (const byte *)&signature_[0],
                                signature_.size());
}

bool Transaction::SignTransaction(const MyPrivateKey &private_key) {
  std::string public_key = GetPublicKey(private_key);
  if (public_key != sender_) {
    return false;
  }
  CryptoPP::ECDSA<CryptoPP::ECP, CryptoPP::SHA256>::Signer signer(private_key);
  CryptoPP::AutoSeededRandomPool prng;
  CryptoPP::StringSource s(
      GetHash(), true /*pump all*/,
      new CryptoPP::SignerFilter(
          prng, signer,
          new CryptoPP::StringSink(signature_)) // SignerFilter
  );
  return true;
}
} // namespace my_blockchain