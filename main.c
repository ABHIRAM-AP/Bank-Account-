#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bank.h"

int main() {
    srand(time(NULL));
    Bank *head = NULL;
    char name[10];
    int choice = 0, amount = 0;
    int AC1 = 0, AC2 = 0, AccNo = 0;
    
    while (choice != 7) {
        printf("\nWelcome to ABC Bank\n\nPlease Enter your Choice:\n1-Create Account\t2-Deposit\t3-Withdraw\n4-Transfer\t5-Search Account\t6-Display Account\t7-Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter name:");
                scanf("%s", name);
                head = CreateAccount(head, name);
                break;
                
            case 2:
                printf("Enter the Account Number:");
                scanf("%d", &AccNo);
                printf("Enter the amount to be deposited:");
                scanf("%d", &amount);
                head = deposit(head, AccNo, amount);
                printf("Amount deposited Successfully\n");
                displayOneAccount(head, AccNo);
                break;
                
            case 3:
                printf("Enter the Account Number:");
                scanf("%d", &AccNo);
                printf("Enter the amount to be withdrawn:");
                scanf("%d", &amount);
                head = withdraw(head, AccNo, amount);
                displayOneAccount(head, AccNo);
                break;
                
            case 4:
                printf("Enter the 1st Account Number:");
                scanf("%d", &AC1);
                printf("Enter the 2nd Account Number:");
                scanf("%d", &AC2);
                printf("Enter the amount to be transferred:");
                scanf("%d", &amount);
                head = transfer(head, AC1, AC2, amount);
                break;
                
            case 5:
                int searchResult = SearchAccount(head);
                if (searchResult != -1) {
                    printf("Account Exists\n");
                } else {
                    printf("Account doesn't Exist\n");
                }
                break;
                
            case 6:
                display(head);
                break;
        }
    }
    return 0;
}
