#ifndef __TRANSACTION_H__
#define __TRANSACTION_H__
#include <cstdint>
#include <ctime>
#include <string>
using std::string;
namespace my_blockchain {
class Transaction {
private:
  string sender_;
  string receiver_;
  double amount_;

public:
  Transaction(const string &from, const string &to, double amount)
      : sender_(from), receiver_(to), amount_(amount) {}
  inline string GetSender() const { return sender_; }
  inline string GetReceiver() const { return receiver_; }
  inline double GetAmount() const { return amount_; }
};

} // namespace my_blockchain

#endif // __TRANSACTION_H__