#ifndef BANK_H
#define BANK_H

typedef struct Node {
    int AccNo, balance;
    char name[10];
    int pin[4];
    struct Node *next;
} Bank;

// Function declarations
Bank *GetNode();
int accountExists(Bank *account, int AccNo);
Bank *CreateAccount(Bank *account, const char *name);
Bank *deposit(Bank *account, int AccNo, int amount);
Bank *withdraw(Bank *account, int AccNo, int amount);
Bank *transfer(Bank *account, int ac1, int ac2, int amount);
int SearchAccount(Bank *account);
void display(Bank *account);
void displayOneAccount(Bank *account, int AccNo);

#endif // BANK_H
