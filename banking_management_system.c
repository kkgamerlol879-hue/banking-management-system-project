#include<stdio.h>
long long int account_number;
char name[50];
float balance;

int isvalid_account_number(long long acc_num) {
    int count = 0;
    while (acc_num != 0) {
        acc_num /= 10;
        count++;
    }if (count != 11) {
        printf("Invalid account number. It must be 11 digits.\n");
    }
    return count == 11;
}
void create_account() {
    if (account_number >= 12) {
        printf("Maximum number of accounts reached.\n");
        return;
    }
    printf("Enter account number (11 digits): ");
    scanf("%lld", &account_number);
    if (!isvalid_account_number(account_number)) {
        return;
    }
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter initial balance: ");
    scanf("%f", &balance);
    printf("Account created successfully.\n");
}
void deposit() {
    long long int account_number;
    float amount;
    printf("Enter account number: ");
    scanf("%lld", &account_number);
    if (!isvalid_account_number(account_number)) {
        return;
    }
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid amount. Must be greater than 0.\n");
        return; 
    }
    balance += amount;
    printf("Deposit successful. New balance: %.2f\n", balance);
}
void withdraw() {
    long long int account_number;
    float amount;
    printf("Enter account number: ");
    scanf("%lld", &account_number);
    if (!isvalid_account_number(account_number)) {
        return;
    }
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid amount. Must be greater than 0.\n");
        return;
    }
    if (balance < amount) {
        printf("Insufficient balance.\n");
        return;
    }
    balance -= amount;
    printf("Withdrawal successful. New balance: %.2f\n", balance);
}
void display_account() 
{
    long long int account_number;
    printf("Enter account number: ");
    scanf("%lld", &account_number);
    if (!isvalid_account_number(account_number)) 
    {
        return;
    }
}

int main() 
{
    int option;
    do {
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Account\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
    }

while (option != 5);
    if(option == 1) {
        create_account();
    } else if (option == 2) {
        deposit();
    } else if (option == 3) {
        withdraw();
    } else if (option == 4) {
        display_account();
    } else if (option == 5) 
    {
        printf("Exiting...\n");
    } else {
        printf("Invalid option. Please try again.\n");
    }
    return 0;
}