#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount {
private:
    int accountNumber;
    std::string accountHolderName;
    std::string accountType;
    double balance;

public:
    // Constructor
    BankAccount(int accNum, std::string name, std::string type, double initialBalance);

    // Getters
    int getAccountNumber() const;
    std::string getAccountHolderName() const;
    std::string getAccountType() const;
    double getBalance() const;

    // Financial Operations
    void deposit(double amount);
    bool withdraw(double amount);
    void displayCard() const;
    
    // Formatting data for file saving
    std::string toCSV() const;
};

#endif