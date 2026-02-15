#ifndef PREMIUMACCOUNT_H
#define PREMIUMACCOUNT_H

#include "BankAccount.h"
#include <iostream>
#include <string>
using namespace std;

class PremiumAccount : public BankAccount {
private:
    double OverdraftLimit; 

public:
    // Constructor
    PremiumAccount(string id, double bal, double limit) 
        : BankAccount(id, bal) {
        OverdraftLimit = limit;
    }

    bool withdraw(double amount) override {
        if (amount > 0 && (getBalance() + OverdraftLimit) >= amount) {
            // Allow balance to go negative
            setBalance(getBalance() - amount);
            cout << "Withdrawal successful (Overdraft used if needed).\n";
            return true;
        }
        else {
            cout << "Error: Transaction exceeds overdraft limit.\n";
            return false;
        }
    }

    // report
    void generateReport() const override {
        cout << "--- PREMIUM ACCOUNT REPORT ---\n";
        cout << "ID: " << getAccountID() << "\n";
        cout << "Balance: " << getBalance() << "\n";
        cout << "Overdraft Limit: " << OverdraftLimit << "\n";
    }
};

#endif