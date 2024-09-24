#pragma once

#include "types.hpp"

namespace Bank
{
    class Transaction
    {
    private:
        i32 m_transaction_id;           // Unique transaction ID
        BankAccount *m_account;         // Pointer to the account associated with this transaction
        f64 m_amount;                   // Amount to deposit or withdraw
        std::string m_transaction_type; // Deposit or Withdraw

    public:
        Transaction() = default;
        Transaction(i32 transaction_id, BankAccount *account, f64 amount, const std::string &transaction_type);

        void Execute() const;
        void Display() const;
    };
}