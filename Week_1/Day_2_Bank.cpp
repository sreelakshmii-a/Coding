#include <iostream>
#include <string>

class BankAccount {
private:
    std::string depositorName;
    int accountNumber;
    std::string accountType;
    double balance;

public:
    // Constructor to initialize values
    BankAccount(std::string name, int number, std::string type, double initialBalance) {
        depositorName = name;
        accountNumber = number;
        accountType = type;
        balance = initialBalance;
    }

    // Function to deposit an amount
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: $" << amount << std::endl;
        } else {
            std::cout << "Deposit amount must be positive!" << std::endl;
        }
    }

    // Function to withdraw an amount
    void withdraw(double amount) {
        if (amount > 0) {
            if (amount <= balance) {
                balance -= amount;
                std::cout << "Withdrew: $" << amount << std::endl;
            } else {
                std::cout << "Insufficient balance!" << std::endl;
            }
        } else {
            std::cout << "Withdrawal amount must be positive!" << std::endl;
        }
    }

    // Function to display name and balance
    void display() const {
        std::cout << "Account Holder: " << depositorName << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
    }
};

int main() {
    // Create a BankAccount object
    BankAccount account("John Doe", 123456789, "Checking", 1000.0);

    // Display initial details
    std::cout << "Initial Account Details:" << std::endl;
    account.display();

    // Deposit an amount
    account.deposit(500.0);

    // Withdraw an amount
    account.withdraw(200.0);

    // Attempt to withdraw more than the balance
    account.withdraw(2000.0);

    // Display final details
    std::cout << "\nFinal Account Details:" << std::endl;
    account.display();

    return 0;
}
