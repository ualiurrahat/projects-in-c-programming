# Banking System Software

## Overview

This project implements a **Banking System Software** in C that allows users to perform essential banking operations with a user-friendly interface. The program ensures **data integrity** and provides a comprehensive summary of all transactions, making it suitable for learning **financial transaction management** and **structured programming**.

---

## Features

- **Account Creation**: Open an account with a $1000 bonus.
- **Deposit Money**: Add funds to your account.
- **Withdraw Money**: Withdraw funds if the balance is sufficient.
- **Money Transfer**: Simulate money transfer between accounts.
- **Account Details**: View account information, including balance and transaction summaries.
- **Final Summary**: Displays a complete transaction summary before exiting.

---

## How It Works

1. **Account Creation**:

   - Users provide their name and an account number.
   - The account is initialized with a $1000 balance as a welcome bonus.

2. **Banking Operations**:

   - Users can perform deposits, withdrawals, and transfers.
   - Real-time balance updates are provided after every transaction.

3. **Account Details**:

   - Users can check their current balance and view a summary of all transactions.

4. **Exit**:
   - A final transaction summary is displayed before the program terminates.

---

## Menu Options

The program offers the following options through a menu-driven interface:

1. Deposit Money
2. Withdraw Cash
3. Transfer Money
4. Check Account Details
5. Exit

---

## Code Highlights

- **Validation**: Input validation ensures users cannot perform invalid operations (e.g., negative deposits or withdrawals exceeding the balance).
- **Data Integrity**: Transactions are tracked to provide accurate summaries.
- **User-Friendly Design**: A menu-driven interface simplifies the user experience.
- **Clean Exit**: Displays a detailed transaction summary upon exit.

---

## How to Run

1. Clone or download the project files.
2. Compile the `banking_system.c` file using any C compiler:
   ```bash
   gcc banking_system.c -o banking_system
   ```
