#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include "BankAccount.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

class BankSystem {
private:
    std::vector<BankAccount> accounts;
    const std::string filename = "database.txt";
    int nextAccountNumber = 1001;

    int findAccountIndex(int accNum) {
        for (size_t i = 0; i < accounts.size(); ++i) {
            if (accounts[i].getAccountNumber() == accNum) return i;
        }
        return -1;
    }

public:
    BankSystem() { loadFromFile(); }
    ~BankSystem() { saveToFile(); }

    void createAccount(std::string name, std::string type, double initialDeposit) {
        BankAccount newAcc(nextAccountNumber, name, type, initialDeposit);
        accounts.push_back(newAcc);
        std::cout << "\n[SYSTEM] Account provisioned! Your Account Number is: " << nextAccountNumber << "\n";
        nextAccountNumber++;
        saveToFile();
    }

    void depositTo(int accNum, double amount) {
        int idx = findAccountIndex(accNum);
        if (idx != -1) {
            accounts[idx].deposit(amount);
            saveToFile();
        } else {
            std::cout << "\n[ERROR] Account number " << accNum << " not found.\n";
        }
    }

    void withdrawFrom(int accNum, double amount) {
        int idx = findAccountIndex(accNum);
        if (idx != -1) {
            if (accounts[idx].withdraw(amount)) saveToFile();
        } else {
            std::cout << "\n[ERROR] Account number " << accNum << " not found.\n";
        }
    }

    void displayAccount(int accNum) {
        int idx = findAccountIndex(accNum);
        if (idx != -1) accounts[idx].displayCard();
        else std::cout << "\n[ERROR] Account not found.\n";
    }

    void displayAll() {
        if (accounts.empty()) {
            std::cout << "\n[SYSTEM] No registry records found.\n";
            return;
        }
        for (const auto& acc : accounts) acc.displayCard();
    }

    void saveToFile() {
        std::ofstream outFile(filename, std::ios::trunc);
        if (!outFile) return;
        for (const auto& acc : accounts) {
            outFile << acc.toCSV() << "\n";
        }
        outFile.close();
    }

    void loadFromFile() {
        std::ifstream inFile(filename);
        if (!inFile) return;
        accounts.clear();
        std::string line;
        int maxId = 1000;

        while (std::getline(inFile, line)) {
            if (line.empty()) continue;
            std::stringstream ss(line);
            std::string idStr, name, type, balStr;
            
            std::getline(ss, idStr, ',');
            std::getline(ss, name, ',');
            std::getline(ss, type, ',');
            std::getline(ss, balStr, ',');

            int id = std::stoi(idStr);
            double bal = std::stod(balStr);
            
            accounts.push_back(BankAccount(id, name, type, bal));
            if (id > maxId) maxId = id;
        }
        inFile.close();
        nextAccountNumber = maxId + 1;
    }
};

#endif