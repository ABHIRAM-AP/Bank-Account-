#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "bank.h"



Bank *GetNode() {
    Bank *b = (Bank *)malloc(sizeof(Bank));
    return b;
}

int accountExists(Bank *account, int AccNo) {
    Bank *ptr = account;
    while (ptr != NULL) {
        if (ptr->AccNo == AccNo) {
            return 1;
        }
        ptr = ptr->next;
    }
    return 0;
}

Bank *CreateAccount(Bank *account, const char *name) {
    Bank *newNode = GetNode();
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return account;
    }
    
    int uniqueAccNo;
    do {
        uniqueAccNo = rand() % 90000 + 10000;
    } while (accountExists(account, uniqueAccNo));
    
    newNode->AccNo = uniqueAccNo;
    newNode->balance = 0;
    strncpy(newNode->name, name, sizeof(newNode->name) - 1);
    newNode->name[sizeof(newNode->name) - 1] = '\0';
   
    for (int i = 0; i < 4; i++) {
        newNode->pin[i] = rand() % 10;
    }
    
    newNode->next = NULL;
    printf("Account Created Successfully\nAccount Number is %d\n", newNode->AccNo);
    
    if (account == NULL) {
        return newNode;
    } else {
        Bank *temp = account;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    return account;
}

Bank *deposit(Bank *account, int AccNo, int amount) {
    Bank *ptr = account;
    int found = 0;
    while (ptr != NULL) {
        if (ptr->AccNo == AccNo) {
            ptr->balance += amount;
            found = 1;
            break;
        }
        ptr = ptr->next;
    }
    if (!found) {
        printf("Account doesn't Exist\n");
    }
    return account;
}

Bank *withdraw(Bank *account, int AccNo, int amount) {
    Bank *ptr = account;
    int found = 0;
    while (ptr != NULL) {
        if (ptr->AccNo == AccNo) {
            found = 1;
            if (ptr->balance >= amount) {
                ptr->balance -= amount;
                printf("Amount withdrawn successfully.\n");
            } else {
                printf("Insufficient Balance\n");
            }
            break;
        }
        ptr = ptr->next;
    }
    if (!found) {
        printf("Account doesn't exist.\n");
    }
    return account;
}

Bank *transfer(Bank *account, int ac1, int ac2, int amount) {
    Bank *sender = NULL, *receiver = NULL, *ptr = account;
    int found = 0;
    
    while (ptr != NULL) {
        if (ptr->AccNo == ac1) sender = ptr;
        if (ptr->AccNo == ac2) receiver = ptr;
        ptr = ptr->next;
    }
    
    if (sender && receiver) {
        if (sender->balance >= amount) {
            sender->balance -= amount;
            receiver->balance += amount;
            printf("Transfer successful.\n");
        } else {
            printf("Insufficient balance in sender's account.\n");
        }
    } else {
        printf("One or both accounts do not exist.\n");
    }

    return account;
}

int SearchAccount(Bank *account) {
    int option = 0, acc = 0;
    char name[10];
    Bank *ptr = account;
    printf("How to Search?\n1-Account Number\t2-Name:");
    scanf("%d", &option);
    
    switch (option) {
        case 1:
            printf("Enter account number:");
            scanf("%d", &acc);
            while (ptr != NULL) {
                if (ptr->AccNo == acc) {
                    return 1;
                } else {
                    return 0;
                }
                ptr = ptr->next;
            }
            break;
            
        case 2:
            printf("Enter name of Account Holder:");
            scanf("%s", name);
            while (ptr != NULL) {
                if (strcmp(ptr->name, name) == 0) {
                    return 1;
                } else {
                    return 0;
                }
                ptr = ptr->next;
            }
            break;
    }
    return -1;
}

void display(Bank *account) {
    Bank *ptr = account;
    int j = 0;
    
    while (ptr != NULL) {
        printf("\nDetails of Person %d", (j + 1));
        printf("\n");
        printf("Name: %s", ptr->name);
        printf("\nAccount Number: %d", ptr->AccNo);
        printf("\nPin:");
        for (int i = 0; i < 4; i++) {
            printf("%d", ptr->pin[i]);
        }
        printf("\nBalance: %d\n", ptr->balance);
        ptr = ptr->next;
        j++;
    }
    printf("\n\n\n\n");
}
void displayOneAccount(Bank *account,int AccNo)
{
    Bank *ptr=account;
    
    while(ptr!=NULL)
    {
        if(ptr->AccNo == AccNo)
        {
        printf("\nDetails are:");
        printf("\n");
        printf("Name: %s",ptr->name);
        printf("\nAccount Number: %d",ptr->AccNo);
        printf("\nPin:");
        for(int i=0;i<4;i++)
        {
            printf("%d",ptr->pin[i]);
        }
        printf("\nBalance: %d\n",ptr->balance);
        }
        ptr=ptr->next;
    }
}