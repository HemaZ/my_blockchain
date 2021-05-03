#ifndef __MY_BLOCKCHAIN_UTILS_H__
#define __MY_BLOCKCHAIN_UTILS_H__
#include "cryptopp/cryptlib.h"
#include "cryptopp/integer.h"
#include "cryptopp/oids.h"
#include "cryptopp/osrng.h"
#include "cryptopp/secblock.h"
#include "sha256.hpp"
#include <cryptopp/eccrypto.h>
#include <cryptopp/hex.h>
#include <string>
namespace my_blockchain {
using MyPrivateKey =
    CryptoPP::ECDSA<CryptoPP::ECP, CryptoPP::SHA256>::PrivateKey;
using MyPublicKey = CryptoPP::ECDSA<CryptoPP::ECP, CryptoPP::SHA256>::PublicKey;
/**
 * @brief Get the Public Key as Hex string from Private key.
 *
 * @param private_key
 * @return std::string Public Key as Hex string
 */
std::string GetPublicKey(const MyPrivateKey &private_key);
/**
 * @brief Get the Public Key object from a hex string.
 *
 * @param public_key hex string represents the public key.
 * @return MyPublicKey
 */
MyPublicKey GetPublicKey(const std::string &public_key);
} // namespace my_blockchain

#endif // __MY_BLOCKCHAIN_UTILS_H__