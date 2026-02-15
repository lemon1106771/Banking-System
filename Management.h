#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <vector>
#include "BankAccount.h" 
#include <iostream>
using namespace std;

class Management {
private:
    vector<BankAccount*> accounts;

public:
    void addAccount(BankAccount* acc) {
        accounts.push_back(acc);
    }

    void showAllReports() const {
        if (accounts.empty()) {
            cout << "No accounts to display.\n";
            return;
        }

        cout << "\n--- ACCOUNT MANAGEMENT REPORT (" << accounts.size() << " accounts) ---\n";
        for (int i = 0; i < accounts.size(); i++) {
            // "->"" means "follow the pointer and call the function"
            accounts[i]->generateReport(); 
            cout << "-------------------------\n";
        }
    }
// This was actually done by Gemini. Apperently it has something to do with memory leaks so i'll just leave it here
    ~Management() {
    // Loop through every account we have
    for (BankAccount* acc : accounts) {
        delete acc; // Go to that memory address ana delete that
    }
}
};
#endif