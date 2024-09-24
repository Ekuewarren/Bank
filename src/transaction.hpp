#pragma once

#include "types.hpp"

namespace Bank
{
    class Transaction
    {
    private:
        i32 m_transaction_id;           // Unique transaction ID
        BankAccount& m_account;         // Reference to the account associated with this transaction
        f64 m_amount;                   // Amount to deposit or withdraw
        std::string m_transaction_type; // Deposit or Withdraw
        void Execute() const;

    public:
        Transaction() = default;
        Transaction(i32 transaction_id, BankAccount *account, f64 amount, const std::string &transaction_type);

        void Display() const;
    };
}
