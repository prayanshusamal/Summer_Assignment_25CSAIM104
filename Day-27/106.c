#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 50      //Write a program to Create employee management system.
#define NAME_LEN 50
#define DEPT_LEN 30

// Structure to store employee details
typedef struct 
{
    int id;
    char name[NAME_LEN];
    char department[DEPT_LEN];
    float baseSalary;
} 
Employee;

// Global tracking variables
Employee staff[MAX_EMPLOYEES];
int totalEmployees = 0;

// Function declarations
void showMenu();
void insertEmployee();
void listEmployees();
void findEmployee();
void runningPayroll();

int main() 
{
    int selection;

    while (1) 
    {
        showMenu();
        printf("Select an option: ");
        if (scanf("%d", &selection) != 1) 
        {
            printf("Invalid system input. Shutting down.\n");
            break;
        }

        switch (selection) 
        {
            case 1:
                insertEmployee();
                break;
            case 2:
                listEmployees();
                break;
            case 3:
                findEmployee();
                break;
            case 4:
                runningPayroll();
                break;
            case 5:
                printf("Exiting system. Have a great day!\n");
                return 0;
            default:
                printf("Invalid selection. Try again.\n");
        }
    }
    return 0;
}

void showMenu() 
{
    printf("\n--- Employee Management System ---\n");
    printf("1. Add Employee\n");
    printf("2. List All Employees\n");
    printf("3. Search Employee by ID\n");
    printf("4. Calculate Total Payroll\n");
    printf("5. Exit\n");
    printf("----------------------------------\n");
}

// Function to add a unique employee record
void insertEmployee() 
{
    if (totalEmployees >= MAX_EMPLOYEES) 
    {
        printf("Database full. Cannot add more employees.\n");
        return;
    }

    Employee emp;
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);

    // Validate ID uniqueness
    for (int i = 0; i < totalEmployees; i++) 
    {
        if (staff[i].id == emp.id) 
        {
            printf("Error: ID %d is already assigned.\n", emp.id);
            return;
        }
    }

    printf("Enter Name: ");
    getchar(); // Flush leftover newline characters
    fgets(emp.name, NAME_LEN, stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; // Strip trailing newline

    printf("Enter Department: ");
    fgets(emp.department, DEPT_LEN, stdin);
    emp.department[strcspn(emp.department, "\n")] = 0;

    printf("Enter Base Salary: ");
    scanf("%f", &emp.baseSalary);

    staff[totalEmployees] = emp;
    totalEmployees++;
    printf("Employee added successfully.\n");
}

// Function to print all employee records
void listEmployees() 
{
    if (totalEmployees == 0) 
    {
        printf("No records found in the database.\n");
        return;
    }

    printf("\n%-10s %-25s %-20s %-12s\n", "ID", "Name", "Department", "Salary");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < totalEmployees; i++) 
    {
        printf("%-10d %-25s %-20s $%-11.2f\n", 
               staff[i].id, staff[i].name, staff[i].department, staff[i].baseSalary);
    }
}

// Function to find an employee by their unique ID
void findEmployee() 
{
    if (totalEmployees == 0) 
    {
        printf("Database empty.\n");
        return;
    }

    int targetId;
    printf("Enter Employee ID to search: ");
    scanf("%d", &targetId);

    for (int i = 0; i < totalEmployees; i++) 
    {
        if (staff[i].id == targetId) 
        {
            printf("\nEmployee Profile Found:\n");
            printf("ID: %d\n", staff[i].id);
            printf("Name: %s\n", staff[i].name);
            printf("Department: %s\n", staff[i].department);
            printf("Base Salary: $%.2f\n", staff[i].baseSalary);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", targetId);
}

// Function to sum up payroll expenses
void runningPayroll() 
{
    if (totalEmployees == 0) 
    {
        printf("No active employees to calculate payroll.\n");
        return;
    }

    float totalPayroll = 0;
    for (int i = 0; i < totalEmployees; i++) 
    {
        totalPayroll += staff[i].baseSalary;
    }
    printf("\nTotal Operational Salary Expense: $%.2f\n", totalPayroll);
}
