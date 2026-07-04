#include <stdio.h>

int main()    //To Create ATM simulation.
{
    int pin, enteredPin, choice;
    float balance = 1000.0;
    pin = 1234; 

    printf("Welcome to the ATM!\n");
    printf("Enter your PIN: ");
    scanf("%d", &enteredPin);

    if (enteredPin == pin)
    {
        while (1)
        {
            printf("1. Check Balance\n2. Withdraw\n3. Deposit\n4. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                    printf("Your balance is: $%.2f\n", balance);
                    break;
                case 2:
                    float withdrawAmount;
                    printf("Enter the amount to withdraw: ");
                    scanf("%f", &withdrawAmount);
                    if (withdrawAmount <= balance)
                    {
                        balance -= withdrawAmount;
                        printf("Withdrawal successful. Your new balance is: $%.2f\n", balance);
                    }
                    else
                    {
                        printf("Insufficient funds.\n");
                    }
                    break;
                case 3:
                    float depositAmount;
                    printf("Enter the amount to deposit: ");
                    scanf("%f", &depositAmount);
                    balance += depositAmount;
                    printf("Deposit successful. Your new balance is: $%.2f\n", balance);
                    break;
                case 4:
                    printf("Thank you for using the ATM!\n");
                    return 0;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        }
    }
    else
    {
        printf("Incorrect PIN. Please try again.\n");
    }

    return 0;
}