#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include "reportable.h"
#include <string>
using namespace std; 

class BankAccount: public Reportable  {
    private: 
    double balance;
    string AccountID;

    public:
    // future use
    virtual bool withdraw(double WithdrawAmount) = 0;
    // constructor
    BankAccount(string id, double initialBalance) {
        AccountID = id;         
        balance = initialBalance; 
    }
    // these are the getters
    double getBalance() const {
        return balance; 
    }
    string getAccountID() const { 
        return AccountID; 
    }
    //money depositing function
    void DepositBalance(double DepositAmount) { 
        if (DepositAmount > 0) {
        balance += DepositAmount;
        }
    }
    protected:
    void setBalance(double newBal) {
        balance = newBal;
    }
};

#endif