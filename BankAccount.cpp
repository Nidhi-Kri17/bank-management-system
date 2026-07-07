#include "BankAccount.h"
#include <iostream>
#include <iomanip>

BankAccount::BankAccount(int accNum, std::string name, std::string type, double initialBalance) 
    : accountNumber(accNum), accountHolderName(name), accountType(type), balance(initialBalance) {}

int BankAccount::getAccountNumber() const { return accountNumber; }
std::string BankAccount::getAccountHolderName() const { return accountHolderName; }
std::string BankAccount::getAccountType() const { return accountType; }
double BankAccount::getBalance() const { return balance; }

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "\n[SUCCESS] Deposited $" << std::fixed << std::setprecision(2) << amount << " successfully.\n";
    } else {
        std::cout << "\n[ERROR] Deposit amount must be positive.\n";
    }
}

bool BankAccount::withdraw(double amount) {
    if (amount <= 0) {
        std::cout << "\n[ERROR] Withdrawal amount must be positive.\n";
        return false;
    }
    if (amount > balance) {
        std::cout << "\n[DENIED] Insufficient funds. Available balance: $" << balance << "\n";
        return false;
    }
    balance -= amount;
    std::cout << "\n[SUCCESS] Withdrew $" << std::fixed << std::setprecision(2) << amount << " successfully.\n";
    return true;
}

void BankAccount::displayCard() const {
    std::cout << "\n==========================================";
    std::cout << "\n  Account ID     : " << accountNumber;
    std::cout << "\n  Holder Name    : " << accountHolderName;
    std::cout << "\n  Account Type   : " << accountType;
    std::cout << "\n  Current Balance: $" << std::fixed << std::setprecision(2) << balance;
    std::cout << "\n==========================================\n";
}

std::string BankAccount::toCSV() const {
    return std::to_string(accountNumber) + "," + accountHolderName + "," + accountType + "," + std::to_string(balance);
}