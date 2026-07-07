# Modular Banking Management Terminal (C++)

A robust, production-ready console banking application built with modern C++17 utilizing object-oriented principles, modular architecture, and file streams for data persistence.

## 🛠️ Features
- **Data Persistence:** Account details auto-save to and load from a flat-file database (`database.txt`).
- **Defensive Input Handling:** Built-in validation loops prevent terminal crashes from illegal input types.
- **Encapsulated Logic:** Strict separation of data access and mutation to protect account balances.

## 💻 How to Run
```bash
g++ -std=c++17 main.cpp BankAccount.cpp -o BankSystem
BankSystem
