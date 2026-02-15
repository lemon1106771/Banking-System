#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "bankaccount.h"
#include <string>
#include <iostream>
using namespace std; 

class SavingsAccount: public BankAccount {
    private:
    double InterestRate; 

    public:
    //constructor
    SavingsAccount(string id, double bal, double rate) : BankAccount(id, bal) {
        InterestRate = rate;
    }
    
    //withdrawing for normal account
    bool withdraw(double amount) override {
        if (amount > 0 && amount <= getBalance()) {
            setBalance(getBalance() - amount);
            return true;
        }
        else {
            cout << "Error: Insufficient funds or invalid amount.\n";
            return false;
        }
    }
    
    //report
    void generateReport() const override {
        cout << "--- SAVINGS ACCOUNT REPORT ---\n";
        cout << "ID: " << getAccountID() << "\n";
        cout << "Balance: " << getBalance() << "\n";
        cout << "Interest Rate: " << InterestRate << "%\n";
    }
    
    //function to allow interest rate to be applied into the balance
    void applyInterest() {
        double interest = getBalance() * (InterestRate / 100);
        DepositBalance(interest);
        cout << "Interest Applied: " << interest << "\n";
    }
};
#endif