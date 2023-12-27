#include "main.h"
void createAccount() {
    struct BankAccount newAccount;

    printf("Enter your name: ");
    scanf("%s", newAccount.name);

    printf("Enter your account number: ");
    scanf("%d", &newAccount.accountNumber);

    printf("Enter initial balance: ");
    scanf("%f", &newAccount.balance);

    FILE *file = fopen("accounts.txt", "a");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s %d %.2f\n", newAccount.name, newAccount.accountNumber, newAccount.balance);

    fclose(file);

    printf("Account created successfully.\n");
}