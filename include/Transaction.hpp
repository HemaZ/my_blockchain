#ifndef __TRANSACTION_H__
#define __TRANSACTION_H__
#include "sha256.hpp"
#include "utils.hpp"
#include <cstdint>
#include <ctime>
#include <iostream>
#include <string>
using namespace CryptoPP;
using std::string;
namespace my_blockchain {
class Transaction {
private:
  string sender_;
  string receiver_;
  double amount_;
  string signature_ = "";

public:
  /**
   * @brief Construct a new Transaction object.
   *
   * @param from Sender address (public key).
   * @param to Receiver address (public key).
   * @param amount Amount to be sent.
   */
  Transaction(const string &from, const string &to, double amount)
      : sender_(from), receiver_(to), amount_(amount) {}
  /**
   * @brief Get the Sender object
   *
   * @return string
   */
  string GetSender() const { return sender_; }
  /**
   * @brief Get the Receiver object
   *
   * @return string
   */
  string GetReceiver() const { return receiver_; }
  /**
   * @brief Get the Amount object
   *
   * @return double
   */
  double GetAmount() const { return amount_; }
  /**
   * @brief Get the Hash of the transaction.
   *
   * @return string
   */
  inline string GetHash() {
    return sha256(sender_ + receiver_ + std::to_string(amount_));
  }
  /**
   * @brief Sign the transaction with the sender private key.
   *
   * @param private_key The sender private key.
   * @return true Signed successfully.
   * @return false Couldn't be signed.
   */
  bool SignTransaction(const MyPrivateKey &private_key);
  /**
   * @brief Check if a transaction is signed by the sender.
   *
   * @return true is signed.
   * @return false not signed.
   */
  bool IsValid();
};

} // namespace my_blockchain

#endif // __TRANSACTION_H__