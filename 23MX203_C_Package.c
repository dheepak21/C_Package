#include <stdio.h>

// Structure to represent a bank account
struct BankAccount {
    int accountNumber;
    char accountHolder[50];
    float balance;
};

// Function to create a new account
void createAccount(struct BankAccount *account, int accountNumber, char *accountHolder, float initialBalance) {
    account->accountNumber = accountNumber;
    strcpy(account->accountHolder, accountHolder);
    account->balance = initialBalance;
}

// Function to deposit money into an account
void deposit(struct BankAccount *account, float amount) {
    account->balance += amount;
    printf("Deposit successful. New balance: %.2f\n", account->balance);
}

// Function to withdraw money from an account
void withdraw(struct BankAccount *account, float amount) {
    if (amount > account->balance) {
        printf("Insufficient funds. Withdrawal failed.\n");
    } else {
        account->balance -= amount;
        printf("Withdrawal successful. New balance: %.2f\n", account->balance);
    }
}

// Function to display account details
void displayAccount(struct BankAccount account) {
    printf("Account Number: %d\n", account.accountNumber);
    printf("Account Holder: %s\n", account.accountHolder);
    printf("Balance: %.2f\n", account.balance);
}

int main() {
    struct BankAccount account;
    int choice;
    float amount;

    // Create an account with initial balance of 0
    createAccount(&account, 123456, "Dheepak", 0.0);

    do {
        // Display menu
        printf("\nBanking System Menu\n");
        printf("1. Display Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAccount(account);
                break;
            case 2:
                printf("Enter the amount to deposit: ");
                scanf("%f", &amount);
                deposit(&account, amount);
                break;
            case 3:
                printf("Enter the amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(&account, amount);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
