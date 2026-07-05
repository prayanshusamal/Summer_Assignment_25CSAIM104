#include <stdio.h>
#include <string.h>

#define MAX_STAFF 50     //Write a program to Create salary management system.
#define NAME_LIMIT 50

// Structure to hold complete salary information
typedef struct 
{
    int empId;
    char empName[NAME_LIMIT];
    float baseSalary;
    float allowance;    // e.g., Medical, HRA
    float deduction;    // e.g., Tax, Insurance
    float netSalary;
} 
SalaryRecord;

// Global storage arrays
SalaryRecord database[MAX_STAFF];
int recordCount = 0;

// Function declarations
void displayMainMenu();
void addNewRecord();
void calculateNetSalary(SalaryRecord *record);
void printAllSalaryRecords();
void generatePayslip();

int main() 
{
    int userOption;

    while (1) 
    {
        displayMainMenu();
        printf("Choose an option: ");
        if (scanf("%d", &userOption) != 1) 
        {
            printf("Invalid data entered. System shutting down.\n");
            break;
        }

        switch (userOption) 
        {
            case 1:
                addNewRecord();
                break;
            case 2:
                printAllSalaryRecords();
                break;
            case 3:
                generatePayslip();
                break;
            case 4:
                printf("Exiting Salary System. Goodbye!\n");
                return 0;
            default:
                printf("Option not recognized. Please retry.\n");
        }
    }
    return 0;
}

void displayMainMenu() 
{
    printf("\n==== Salary Management System ====\n");
    printf("1. Add Employee Salary Details\n");
    printf("2. View All Salary Summaries\n");
    printf("3. Generate Individual Payslip\n");
    printf("4. Exit\n");
    printf("==================================\n");
}

// Core processing function to find total net pay
void calculateNetSalary(SalaryRecord *record) 
{
    record->netSalary = (record->baseSalary + record->allowance) - record->deduction;
}

// Function to collect data and write to record
void addNewRecord() 
{
    if (recordCount >= MAX_STAFF) 
    {
        printf("Error: System memory limit reached.\n");
        return;
    }

    SalaryRecord temp;
    printf("Enter Employee ID: ");
    scanf("%d", &temp.empId);

    // Ensure employee ID stays unique
    for (int i = 0; i < recordCount; i++) 
    {
        if (database[i].empId == temp.empId) 
        {
            printf("Error: Record for ID %d already exists.\n", temp.empId);
            return;
        }
    }

    printf("Enter Employee Name: ");
    getchar(); // Clear stray newline character
    fgets(temp.empName, NAME_LIMIT, stdin);
    temp.empName[strcspn(temp.empName, "\n")] = 0; // Remove newlines

    printf("Enter Base Monthly Salary: ");
    scanf("%f", &temp.baseSalary);

    printf("Enter Allowances (HRA/Medical): ");
    scanf("%f", &temp.allowance);

    printf("Enter Deductions (Tax/PF): ");
    scanf("%f", &temp.deduction);

    // Business rule execution
    calculateNetSalary(&temp);

    database[recordCount] = temp;
    recordCount++;
    printf("Salary data saved successfully!\n");
}

// Function to present data globally
void printAllSalaryRecords() 
{
    if (recordCount == 0) 
    {
        printf("No active salary profiles available.\n");
        return;
    }

    printf("\n%-8s %-25s %-12s %-12s %-12s %-12s\n", 
           "ID", "Name", "Base", "Allowance", "Deduction", "Net Pay");
    printf("------------------------------------------------------------------------------------\n");
    for (int i = 0; i < recordCount; i++) 
    {
        printf("%-8d %-25s %-12.2f %-12.2f %-12.2f %-12.2f\n",
               database[i].empId, database[i].empName, database[i].baseSalary,
               database[i].allowance, database[i].deduction, database[i].netSalary);
    }
}

// Function to filter and show detailed individual statements
void generatePayslip() 
{
    if (recordCount == 0) 
    {
        printf("No payroll statements available to generate.\n");
        return;
    }

    int checkId;
    printf("Enter Employee ID for Payslip: ");
    scanf("%d", &checkId);

    for (int i = 0; i < recordCount; i++) 
    {
        if (database[i].empId == checkId) 
        {
            printf("\n========================================\n");
            printf("            OFFICIAL PAYSLIP            \n");
            printf("========================================\n");
            printf("Employee ID   : %d\n", database[i].empId);
            printf("Employee Name : %s\n", database[i].empName);
            printf("----------------------------------------\n");
            printf("Earnings:\n");
            printf("  (+) Base Salary : $%.2f\n", database[i].baseSalary);
            printf("  (+) Allowances  : $%.2f\n", database[i].allowance);
            printf("Deductions:\n");
            printf("  (-) Deductions  : $%.2f\n", database[i].deduction);
            printf("----------------------------------------\n");
            printf("NET TAKE HOME : $%.2f\n", database[i].netSalary);
            printf("========================================\n");
            return;
        }
    }
    printf("Employee profile matching ID %d not located.\n", checkId);
}
