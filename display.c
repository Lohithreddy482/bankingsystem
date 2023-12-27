#include "main.h"
void displayAccount() {
    int accountNumber;
    printf("Enter your account number: ");
    scanf("%d", &accountNumber);

    struct BankAccount loadedAccount;
    FILE *file = fopen("accounts.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %d %f", loadedAccount.name, &loadedAccount.accountNumber, &loadedAccount.balance) == 3) {
        if (loadedAccount.accountNumber == accountNumber) {
            printf("\nAccount Information:\n");
            printf("Name: %s\n", loadedAccount.name);
            printf("Account Number: %d\n", loadedAccount.accountNumber);
            printf("Balance: $%.2f\n", loadedAccount.balance);

            fclose(file);
            return;
        }
    }

    printf("Account not found.\n");
    fclose(file);
}
