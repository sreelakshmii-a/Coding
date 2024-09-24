#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_ACCOUNT_TYPE_LENGTH 50

// Define a struct to represent a bank account
typedef struct {
    char depositorName[MAX_NAME_LENGTH];
    int accountNumber;
    char accountType[MAX_ACCOUNT_TYPE_LENGTH];
    double balance;
} BankAccount;

// Function to initialize the bank account
void initializeAccount(BankAccount* account, const char* name, int number, const char* type, double initialBalance) {
    strncpy(account->depositorName, name, MAX_NAME_LENGTH);
    account->accountNumber = number;
    strncpy(account->accountType, type, MAX_ACCOUNT_TYPE_LENGTH);
    account->balance = initialBalance;
}

// Function to deposit an amount into the account
void deposit(BankAccount* account, double amount) {
    if (amount > 0) {
        account->balance += amount;
        printf("Deposited: $%.2f\n", amount);
    } else {
        printf("Deposit amount must be positive!\n");
    }
}

// Function to withdraw an amount from the account
void withdraw(BankAccount* account, double amount) {
    if (amount > 0) {
        if (amount <= account->balance) {
            account->balance -= amount;
            printf("Withdrew: $%.2f\n", amount);
        } else {
            printf("Insufficient balance!\n");
        }
    } else {
        printf("Withdrawal amount must be positive!\n");
    }
}


void displayAccount(const BankAccount* account) {
    printf("Account Holder: %s\n", account->depositorName);
    printf("Balance: $%.2f\n", account->balance);
}

int main() {
   
    BankAccount myAccount;
    initializeAccount(&myAccount, "John Doe", 123456789, "Checking", 1000.0);

    
    printf("Initial Account Details:\n");
    displayAccount(&myAccount);

    
    deposit(&myAccount, 500.0);
    withdraw(&myAccount, 200.0);
    withdraw(&myAccount, 2000.0); 

    
    printf("\nFinal Account Details:\n");
    displayAccount(&myAccount);

    return 0;
}
