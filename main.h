#include <stdio.h>
#include <stdlib.h>

struct BankAccount {
    char name[100];
    int accountNumber;
    float balance;
};

// Function prototypes
extern void createAccount();
extern void displayAccount();
extern void deposit();
extern void withdraw();
