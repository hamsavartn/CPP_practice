#include <stdio.h>

void showMenu() {
    printf("\n--- SIMPLE BANK SIMULATOR ---\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    float balance = 1000.00; // Starting balance
    int choice;
    float amount;

    do {
        showMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("\nYour current balance is: $%.2f\n", balance);
                break;
            case 2:
                printf("\nEnter amount to deposit: $");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("Successfully deposited $%.2f. New balance: $%.2f\n", amount, balance);
                } else {
                    printf("Invalid deposit amount.\n");
                }
                break;
            case 3:
                printf("\nEnter amount to withdraw: $");
                scanf("%f", &amount);
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    printf("Successfully withdrew $%.2f. New balance: $%.2f\n", amount, balance);
                } else if (amount > balance) {
                    printf("Insufficient funds! Your balance is $%.2f\n", balance);
                } else {
                    printf("Invalid withdrawal amount.\n");
                }
                break;
            case 4:
                printf("\nThank you for using the Bank Simulator. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please select 1 through 4.\n");
        }
    } while (choice != 4);

    return 0;
}
