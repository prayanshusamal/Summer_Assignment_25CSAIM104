#include <stdio.h>
#include <string.h>

#define MAX_STAFF 100  //Write a program to Create marksheet generation system.
#define TEXT_LIMIT 50

// Structure to store individual employee details
typedef struct 
{
    int employeeId;
    char fullName[TEXT_LIMIT];
    char designation[TEXT_LIMIT];
    float salary;
} 
Employee;

// Global tracking variables
Employee staffRegistry[MAX_STAFF];
int totalActiveStaff = 0;

// Function declarations
void displaySystemMenu();
void addNewEmployee();
void displayAllEmployees();
void searchEmployeeById();
void performSalaryAudit();

int main() 
{
    int userChoice;

    while (1) 
    {
        displaySystemMenu();
        printf("Please choose an operation: ");
        
        // Input safety check
        if (scanf("%d", &userChoice) != 1) 
        {
            printf("Error reading numerical input. System closing.\n");
            break;
        }

        switch (userChoice) 
        {
            case 1:
                addNewEmployee();
                break;
            case 2:
                displayAllEmployees();
                break;
            case 3:
                searchEmployeeById();
                break;
            case 4:
                performSalaryAudit();
                break;
            case 5:
                printf("Exiting Employee System. Have a productive day!\n");
                return 0;
            default:
                printf("Invalid selection! Please enter a number between 1 and 5.\n");
        }
    }
    return 0;
}

// Function to print application menu options
void displaySystemMenu() 
{
    printf("\n=================== EMPLOYEE MANAGEMENT SYSTEM ===================\n");
    printf("1. Add New Employee Record\n");
    printf("2. List All Active Employee Profiles\n");
    printf("3. Search Employee by Identification ID\n");
    printf("4. Run Department Budget & Salary Audit\n");
    printf("5. Exit System Framework\n");
    printf("==================================================================\n");
}

// Function to safely add a unique employee to memory
void addNewEmployee() 
{
    if (totalActiveStaff >= MAX_STAFF) 
    {
        printf("System Error: Storage allocation limit reached.\n");
        return;
    }

    Employee newEmp;
    printf("Enter Employee ID (Integers only): ");
    scanf("%d", &newEmp.employeeId);

    // Verify ID uniqueness to prevent database conflicts
    for (int i = 0; i < totalActiveStaff; i++) 
    {
        if (staffRegistry[i].employeeId == newEmp.employeeId) 
        {
            printf("Abort: Employee ID %d already exists in the registry.\n", newEmp.employeeId);
            return;
        }
    }

    printf("Enter Full Name: ");
    getchar(); // Purge trailing newline character from the stream buffer
    fgets(newEmp.fullName, TEXT_LIMIT, stdin);
    newEmp.fullName[strcspn(newEmp.fullName, "\n")] = 0; // Strip trailing newline

    printf("Enter Job Designation: ");
    fgets(newEmp.designation, TEXT_LIMIT, stdin);
    newEmp.designation[strcspn(newEmp.designation, "\n")] = 0;

    printf("Enter Base Monthly Salary: ");
    scanf("%f", &newEmp.salary);

    // Copy temporary data holder object into global memory structure
    staffRegistry[totalActiveStaff] = newEmp;
    totalActiveStaff++;
    printf("Success: Employee record registered and synced.\n");
}

// Function to print formatted data table
void displayAllEmployees() 
{
    if (totalActiveStaff == 0) 
    {
        printf("Database Status: No records found to display.\n");
        return;
    }

    printf("\n%-10s %-25s %-25s %-12s\n", "ID", "Employee Name", "Designation", "Salary");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < totalActiveStaff; i++) 
    {
        printf("%-10d %-25s %-25s $%-11.2f\n", 
               staffRegistry[i].employeeId, 
               staffRegistry[i].fullName, 
               staffRegistry[i].designation, 
               staffRegistry[i].salary);
    }
}

// Function to search individual registry array indices
void searchEmployeeById() 
{
    if (totalActiveStaff == 0) 
    {
        printf("Database Status: Matrix search skipped, zero records active.\n");
        return;
    }

    int searchTargetId;
    printf("Enter Employee ID to locate: ");
    scanf("%d", &searchTargetId);

    for (int i = 0; i < totalActiveStaff; i++) 
    {
        if (staffRegistry[i].employeeId == searchTargetId) 
        {
            printf("\n--- Profile Records Match Located ---\n");
            printf("ID          : %d\n", staffRegistry[i].employeeId);
            printf("Full Name   : %s\n", staffRegistry[i].fullName);
            printf("Designation : %s\n", staffRegistry[i].designation);
            printf("Base Salary : $%.2f\n", staffRegistry[i].salary);
            printf("--------------------------------------\n");
            return;
        }
    }
    printf("Search Failed: Employee ID %d is not registered.\n", searchTargetId);
}

// Function executing operational calculation audits cleanly
void performSalaryAudit() 
{
    if (totalActiveStaff == 0) 
    {
        printf("Audit Aborted: No financial data exists to analyze.\n");
        return;
    }

    float combinedPayrollSum = 0;
    float highestPayAmount = staffRegistry[0].salary; // Initialized properly to prevent indexing errors
    int topEarnerIndex = 0;

    for (int i = 0; i < totalActiveStaff; i++) 
    {
        combinedPayrollSum += staffRegistry[i].salary;
        
        if (staffRegistry[i].salary > highestPayAmount) 
        {
            highestPayAmount = staffRegistry[i].salary;
            topEarnerIndex = i;
        }
    }

    float mathematicalAverage = combinedPayrollSum / totalActiveStaff;

    printf("\n================ FINANCIAL SYSTEM AUDIT ================\n");
    printf(" Total Combined Workforce Payroll : $%.2f\n", combinedPayrollSum);
    printf(" Mathematical Mean Compensation   : $%.2f\n", mathematicalAverage);
    printf(" Top Financial Earner Account     : %s ($%.2f)\n", 
           staffRegistry[topEarnerIndex].fullName, highestPayAmount);
    printf("========================================================\n");
}
