#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100    //Write a program to Create bank account system.
#define NAME_LIMIT 50

// Structure representing an individual bank account
typedef struct 
{
    int accountNumber;
    char accountHolder[NAME_LIMIT];
    double balance;
} 
BankAccount;

// Global ledger matrix array
BankAccount accountLedger[MAX_ACCOUNTS];
int activeAccountsCount = 0;

// Explicitly defined clear function prototypes
void showBankingMenu();
void openNewAccount();
void displayAllAccounts();
void processDeposit();
void processWithdrawal();

int main() 
{
    int operationalChoice;

    while (1) 
    {
        showBankingMenu();
        printf("Select active banking choice: ");
        
        // Defensive input scan validation
        if (scanf("%d", &operationalChoice) != 1) 
        {
            printf("Error matching numeric menu systems. Halting interface immediately.\n");
            break;
        }

        switch (operationalChoice) 
        {
            case 1:
                openNewAccount();
                break;
            case 2:
                displayAllAccounts();
                break;
            case 3:
                processDeposit();
                break;
            case 4:
                processWithdrawal();
                break;
            case 5:
                printf("Closing connection securely to financial vault. Goodbye!\n");
                return 0;
            default:
                printf("Operation code not recognized. Re-enter integer (1-5).\n");
        }
    }
    return 0;
}

// Function to print the vault terminal menu options cleanly
void showBankingMenu() 
{
    printf("\n================ CORE BANKING TERMINAL ================\n");
    printf("1. Open a New Account Profile\n");
    printf("2. List All Active Bank Accounts\n");
    printf("3. Process Cash Deposit\n");
    printf("4. Process Cash Withdrawal\n");
    printf("5. Disconnect Securely\n");
    printf("=======================================================\n");
}

// Function to safely provision new accounts into structural memory limits
void openNewAccount() 
{
    if (activeAccountsCount >= MAX_ACCOUNTS) 
    {
        printf("System Error: Storage thresholds reached. Cannot open more accounts.\n");
        return;
    }

    BankAccount clientAccount;
    printf("Assign New 5-Digit Account Number: ");
    scanf("%d", &clientAccount.accountNumber);

    // Block matching account numbers to enforce strict relational separation
    for (int i = 0; i < activeAccountsCount; i++) 
    {
        if (accountLedger[i].accountNumber == clientAccount.accountNumber) 
        {
            printf("Security Halt: Account Number %d is already assigned.\n", clientAccount.accountNumber);
            return;
        }
    }

    printf("Enter Primary Account Holder Name: ");
    getchar(); // Clear remaining line feed characters out of stream pipelines
    fgets(clientAccount.accountHolder, NAME_LIMIT, stdin);
    clientAccount.accountHolder[strcspn(clientAccount.accountHolder, "\n")] = 0; // Strip trailing newlines

    printf("Input Initial Opening Deposit Amount: INR ");
    scanf("%lf", &clientAccount.balance);

    if (clientAccount.balance < 0) 
    {
        printf("Transaction Denied: Initial ledger balances cannot be negative.\n");
        return;
    }

    // Save into tracking ledger matrix indices
    accountLedger[activeAccountsCount] = clientAccount;
    activeAccountsCount++;
    printf("Success: Bank Account generated and synced.\n");
}

// Function displaying formatted account list metrics
void displayAllAccounts() 
{
    if (activeAccountsCount == 0) 
    {
        printf("Ledger Notice: System currently holds zero active accounts.\n");
        return;
    }

    printf("\n%-15s %-30s %-20s\n", "Account No.", "Account Holder", "Available Balance");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < activeAccountsCount; i++) 
    {
        printf("%-15d %-30s INR %-16.2f\n", 
               accountLedger[i].accountNumber, 
               accountLedger[i].accountHolder, 
               accountLedger[i].balance);
    }
}

// Function processing deposit additions without breaking element integrity
void processDeposit() 
{
    if (activeAccountsCount == 0) 
    {
        printf("Deposit Canceled: Zero ledger structures initialized.\n");
        return;
    }

    int targetedAccountNumber;
    double depositSum;

    printf("Enter Account Number for Deposit: ");
    scanf("%d", &targetedAccountNumber);

    for (int i = 0; i < activeAccountsCount; i++) 
    {
        if (accountLedger[i].accountNumber == targetedAccountNumber) 
        {
            printf("Enter Deposit Cash Amount: INR ");
            scanf("%lf", &depositSum);

            if (depositSum <= 0) 
            {
                printf("Transaction Denied: Deposit amounts must be greater than zero.\n");
                return;
            }

            accountLedger[i].balance += depositSum;
            printf("Success: Balance updated. New Total: INR %.2f\n", accountLedger[i].balance);
            return;
        }
    }
    printf("Search Error: Account Number %d not registered.\n", targetedAccountNumber);
}

// Function applying balance rules to safeguard against overdraft actions
void processWithdrawal() 
{
    if (activeAccountsCount == 0) 
    {
        printf("Withdrawal Canceled: Core registers are empty.\n");
        return;
    }

    int targetedAccountNumber;
    double withdrawalSum;

    printf("Enter Account Number for Withdrawal: ");
    scanf("%d", &targetedAccountNumber);

    for (int i = 0; i < activeAccountsCount; i++) 
    {
        if (accountLedger[i].accountNumber == targetedAccountNumber) 
        {
            printf("Current Holdings: INR %.2f\nEnter Withdrawal Amount: INR ", accountLedger[i].balance);
            scanf("%lf", &withdrawalSum);

            if (withdrawalSum <= 0) 
            {
                printf("Transaction Denied: Withdrawal amounts must be greater than zero.\n");
                return;
            }

            // Enforce protection logic limits against negative numbers
            if (accountLedger[i].balance < withdrawalSum) 
            {
                printf("Security Alert: Transaction declined due to insufficient ledger funds.\n");
                return;
            }

            accountLedger[i].balance -= withdrawalSum;
            printf("Success: Withdrawal finalized. Remaining Funds: INR %.2f\n", accountLedger[i].balance);
            return;
        }
    }
    printf("Search Error: Account Number %d not matched in current registers.\n", targetedAccountNumber);
}
