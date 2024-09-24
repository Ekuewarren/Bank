#include "bank_account.hpp"
#include "transaction.hpp"
#include <iostream>
#include <cassert>

namespace Bank
{
        Transaction::Transaction(i32 transaction_id, BankAccount& account, f64 amount, const std::string &transaction_type)
        : m_transaction_id(transaction_id), m_account(account), m_amount(amount), m_transaction_type(transaction_type)
    {
        // make sure the amount is greater than 0 and the transaction type is valid
        assert(m_amount > 0 && "Amount must be greater than 0");
        assert((m_transaction_type == "Withdraw" || m_transaction_type == "Deposit") && "Invalid transaction type");

        // execute the transaction when the transaction object is created
        Execute();
    }

    // either deposit or withdraw money from the account
    void Transaction::Execute() const
    {
        if (m_transaction_type == "Deposit")
        {
            m_account.Deposit(m_amount);
        }
        else if (m_transaction_type == "Withdraw")
        {
            m_account.Withdraw(m_amount);
        }
    }

    // display the transaction details
    void Transaction::Display() const
    {
        std::cout << "Transaction ID: " << m_transaction_id << std::endl;
        std::cout << "Transaction Type: " << m_transaction_type << std::endl;
        std::cout << "Transaction Amount: $" << m_amount << std::endl;

        // display the account balance
        m_account.ViewBalance();
    }

}
