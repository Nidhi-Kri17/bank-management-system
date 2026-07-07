#include "BankSystem.h"
#include <iostream>
#include <limits>

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    BankSystem system;
    int choice;

    while (true) {
        std::cout << "\n==========================================";
        std::cout << "\n       BANKING MANAGEMENT TERMINAL       ";
        std::cout << "\n==========================================";
        std::cout << "\n 1. Open New Account";
        std::cout << "\n 2. Deposit Funds";
        std::cout << "\n 3. Withdraw Funds";
        std::cout << "\n 4. Inquiry Account Details";
        std::cout << "\n 5. Display System Ledger";
        std::cout << "\n 6. Secure Exit";
        std::cout << "\n==========================================";
        std::cout << "\nSelect Operation (1-6): ";
        
        if (!(std::cin >> choice)) {
            std::cout << "\n[ERROR] Invalid numerical entry.\n";
            clearInputBuffer();
            continue;
        }

        if (choice == 6) {
            std::cout << "\n[SYSTEM] Operations committed to disk safely. Goodbye.\n";
            break;
        }

        switch (choice) {
            case 1: {
                std::string name, type;
                double deposit;
                std::cout << "Enter Full Name: ";
                clearInputBuffer();
                std::getline(std::cin, name);
                std::cout << "Enter Account Type (Savings/Current): ";
                std::cin >> type;
                std::cout << "Enter Initial Deposit Amount: $";
                if (!(std::cin >> deposit)) {
                    std::cout << "\n[ERROR] Invalid deposit input.\n";
                    clearInputBuffer();
                    break;
                }
                system.createAccount(name, type, deposit);
                break;
            }
            case 2: {
                int id; double amt;
                std::cout << "Enter Target Account ID: ";
                std::cin >> id;
                std::cout << "Enter Deposit Value: $";
                std::cin >> amt;
                system.depositTo(id, amt);
                break;
            }
            case 3: {
                int id; double amt;
                std::cout << "Enter Source Account ID: ";
                std::cin >> id;
                std::cout << "Enter Withdrawal Value: $";
                std::cin >> amt;
                system.withdrawFrom(id, amt);
                break;
            }
            case 4: {
                int id;
                std::cout << "Enter Target Account ID: ";
                std::cin >> id;
                system.displayAccount(id);
                break;
            }
            case 5:
                system.displayAll();
                break;
            default:
                std::cout << "\n[ERROR] Request out of functional range.\n";
        }
    }
    return 0;
}