#include "main.h"
void withdraw() {
    int accountNumber;
    float amount;

    printf("Enter your account number: ");
    scanf("%d", &accountNumber);

    struct BankAccount loadedAccount;
    FILE *file = fopen("accounts.txt", "r+");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %d %f", loadedAccount.name, &loadedAccount.accountNumber, &loadedAccount.balance) == 3) {
        if (loadedAccount.accountNumber == accountNumber) {
            printf("Enter the amount to withdraw: ");
            scanf("%f", &amount);

            if (amount <= loadedAccount.balance) {
                loadedAccount.balance -= amount;

                fseek(file, -sizeof(struct BankAccount), SEEK_CUR);
                fprintf(file, "%s %d %.2f\n", loadedAccount.name, loadedAccount.accountNumber, loadedAccount.balance);

                fclose(file);

                printf("Withdrawal successful. New balance: $%.2f\n", loadedAccount.balance);
            } else {
                printf("Insufficient funds for withdrawal.\n");
            }

            return;
        }
    }

    printf("Account not found.\n");
    fclose(file);
}