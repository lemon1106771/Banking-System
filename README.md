# Banking Management System 

---

## 1. Project Description
This is a console-based app I built to manage different types of bank accounts. Instead of just making one big file, I split the logic into different classes to handle Savings Accounts (with interest) and Premium Accounts (with overdraft limits). It uses a management class to keep everything organized in a single list.

## 2. Class Diagram
The structure below shows how the interface, parent class, and child classes are connected in this project.

## 3. Core OOP Concepts in My Code

### Abstraction
I used abstraction in the BankAccount class by making it an abstract base class. It has a pure virtual function `virtual bool withdraw(...) = 0`. This is important because it prevents the program from ever creating a generic BankAccount object, which wouldn't make sense. It forces the child classes to define their own specific withdrawal rules instead.

### Interface
The Reportable class is the interface for this project. It only contains a pure virtual destructor and the `generateReport()` function. It acts as a contract that ensures any class inheriting from it will definitely have a reporting method that the management system can call.

### Inheritance
Inheritance is used to show the "Is-A" relationship between the classes. SavingsAccount and PremiumAccount both inherit from BankAccount. This let me put the AccountID and balance variables in the parent class so I didn't have to write the same code twice for both account types.

### Polymorphism
Polymorphism happens in my Management class. I have a vector that stores BankAccount pointers. Even though the vector only knows it is holding a BankAccount, when I call `generateReport()` or `withdraw()`, the program is smart enough to jump to the specific version inside SavingsAccount or PremiumAccount based on what kind of object is actually being pointed to at that time.

## 4. Composition vs. Inheritance

### Inheritance (Is-A)
In this project, I used inheritance for the account hierarchy. A PremiumAccount is a BankAccount, so it makes sense for it to inherit everything from the parent.

### Composition (Has-A)
I used composition for the Management class. The manager is not an account; it just has a list of accounts. This is better than inheritance for the manager because it decouples the storage logic from the bank account logic. It makes it easy to add or remove accounts from the list without changing how the actual money logic works.



## 5. How to Compile and Run

### Prerequisites
Make sure you have all the header files and the main file in the same folder:
1. Reportable.h
2. BankAccount.h
3. SavingsAccount.h
4. PremiumAccount.h
5. Management.h
6. main.cpp

### Steps
1. Open your terminal in the project folder.
2. Run the compiler command:
   g++ main.cpp -o BankingSystem
3. Run the program:
   * Windows: BankingSystem.exe
   * Mac/Linux: ./BankingSystem
