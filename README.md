# Banking Management System 

---

## 1. Project Description
This is a console-based app I built to manage different types of bank accounts. Instead of just making one big file, I split the logic into different classes to handle **Savings Accounts** (with interest) and **Premium Accounts** (with overdraft limits). It uses a management class to keep everything organized in a single list.

## 2. Class Diagram

## 3. Core OOP Concepts Explained

* **Abstraction:** I made `BankAccount` an **abstract class**. Since you can't have a "generic" account in real life, I used a pure virtual function (`= 0`) for the withdraw method. This forces the specific accounts to decide their own rules.
* **Interface:** I used `Reportable.h` as an interface. It doesn't store any data; it just acts as a rule that says "any class using this MUST have a `generateReport()` function."
* **Inheritance:** This is the **"Parents-Chikd"** relationship. Both Savings and Premium accounts inherit from `BankAccount`. This allowed me to put shared stuff like `AccountID` and `balance` in one place so I didn't have to rewrite code.
* **Polymorphism:** I used **Runtime Polymorphism** here. The `Management` class stores everything as `BankAccount*` pointers. When the program runs, it’s smart enough to know which version of `generateReport()` to call based on the actual account type.

## 4. Composition vs. Inheritance
I used both of these to keep the design clean:

* **Inheritance (Is-A):** I used this for the relationship between the accounts. A `PremiumAccount` **is** a type of `BankAccount`.
* **Composition (Has-A):** I used this for the `Management` class. The manager **is not** an account; it **has** a vector list of accounts inside it. This makes the system more modular because the manager handles the list while the accounts handle the money.

## 5. How to Compile and Run

### Requirements
Make sure you have all 6 `.h` and `.cpp` files in the same folder:
1. `Reportable.h`
2. `BankAccount.h`
3. `SavingsAccount.h`
4. `PremiumAccount.h`
5. `Management.h`
6. `main.cpp`

### Steps
1. Open your terminal in the project folder.
2. Run the compiler command: or just run the .exe file included I have already built in the folder
   ```bash
   g++ main.cpp -o BankingSystem

