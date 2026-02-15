#include <iostream>
#include <string>
#include "Management.h"
#include "SavingsAccount.h"
#include "PremiumAccount.h"

using namespace std;

int main() {
    Management bank;
    int choice = -1;

    // Hardcoded accounts for testing (You can change these)
    SavingsAccount* s1 = new SavingsAccount("SAV-01", 1000, 3.5);
    PremiumAccount* p1 = new PremiumAccount("PRE-01", 2000, 500);

    bank.addAccount(s1);
    bank.addAccount(p1);

    while (choice != 0) {
        // --- VERTICAL MENU ---
        cout << "\n================================" << endl;
        cout << "   BANKING MANAGEMENT SYSTEM    " << endl;
        cout << "================================" << endl;
        cout << " 1. Deposit $100 (Savings)     " << endl;
        cout << " 2. Withdraw $1500 (Premium)   " << endl;
        cout << " 3. View All Account Reports   " << endl;
        cout << " 4. Apply Monthly Interest Rate (Savings)  " << endl;
        cout << " 0. Exit System                " << endl;
        cout << "================================" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nDepositing to Savings..." << endl;
                s1->DepositBalance(100);
                break;

            case 2:
                cout << "\nWithdrawing from Premium (Overdraft Test)..." << endl;
                if (p1->withdraw(1500)) {
                    cout << "Transaction Approved." << endl;
                    cout << "New Balance: $" << p1->getBalance() << endl;
                }
                break;

            case 3:
                // polymorphism showcasing
                bank.showAllReports();
                break;
            
            case 4: 
                cout << "\nApplying monthly interest to Savings..." << endl;
                cout << "Balance before: $" << s1->getBalance() << endl;
                s1->applyInterest(); 
                cout << "Balance after: $" << s1->getBalance() << endl;
                break;
            
            case 0:
                cout << "\nShutting down system. Goodbye" << endl;
                break;

            default:
                cout << "\n[!] Invalid option. Please try again." << endl;
        }
    }

    return 0; 
}