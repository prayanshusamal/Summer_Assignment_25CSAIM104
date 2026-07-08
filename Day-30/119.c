#include <stdio.h>
#include <string.h>

#define MAX_STAFF 50         //Write a program to Create mini employee management system.
#define STR_BOUND 50

// Structure representing an individual employee record
typedef struct 
{
    int employeeId;
    char fullName[STR_BOUND];
    char role[STR_BOUND];
    float monthlySalary;
} 
MiniEmployee;

// Global roster database tracking array
MiniEmployee staffRoster[MAX_STAFF];
int activeStaffCount = 0;

// Explicit clean function prototypes
void displayMiniRosterMenu();
void insertEmployeeProfile();
void listActiveRoster();
void computePayrollSummary();

int main() 
{
    int terminalChoice;

    while (1) 
    {
        displayMiniRosterMenu();
        printf("Select active system operation: ");
        
        // Defensive input verification check for menu system values
        if (scanf("%d", &terminalChoice) != 1) 
        {
            printf("Error decoding numeric choice fields. Halting program flow.\n");
            break;
        }

        switch (terminalChoice) 
        {
            case 1:
                insertEmployeeProfile();
                break;
            case 2:
                listActiveRoster();
                break;
            case 3:
                computePayrollSummary();
                break;
            case 4:
                printf("Closing Mini Workforce system. Corporate indices stored safely. Goodbye!\n");
                return 0;
            default:
                printf("Operation code unassigned. Input an integer from 1 to 4.\n");
        }
    }
    return 0;
}

// Function to print available employee system actions cleanly
void displayMiniRosterMenu() 
{
    printf("\n============== MINI EMPLOYEE MANAGEMENT ==============\n");
    printf("1. Register a New Employee Record\n");
    printf("2. List All Active Workforce Profiles\n");
    printf("3. Run Workforce Payroll Cost Summary\n");
    printf("4. Shutdown Management Terminal\n");
    printf("======================================================\n");
}

// Function managing input strings and bounds to add employee details safely
void insertEmployeeProfile() 
{
    if (activeStaffCount >= MAX_STAFF) 
    {
        printf("Storage Fault: Maximum corporate registry indices reached.\n");
        return;
    }

    MiniEmployee prospectiveWorker;
    printf("Assign Unique 4-Digit Employee ID: ");
    scanf("%d", &prospectiveWorker.employeeId);

    // Verify ID uniqueness to block record overlapping errors
    for (int i = 0; i < activeStaffCount; i++) 
    {
        if (staffRoster[i].employeeId == prospectiveWorker.employeeId) 
        {
            printf("Conflict Error: Employee ID %d is already registered.\n", prospectiveWorker.employeeId);
            return;
        }
    }

    printf("Enter Legal Full Name: ");
    getchar(); // Clear remaining line feed characters from previous numeric input stream pipelines
    fgets(prospectiveWorker.fullName, STR_BOUND, stdin);
    prospectiveWorker.fullName[strcspn(prospectiveWorker.fullName, "\n")] = 0; // Strip trailing space line feeds

    printf("Enter Job Designation Role: ");
    fgets(prospectiveWorker.role, STR_BOUND, stdin);
    prospectiveWorker.role[strcspn(prospectiveWorker.role, "\n")] = 0;

    printf("Set Monthly Compensation Salary: INR ");
    scanf("%f", &prospectiveWorker.monthlySalary);

    // Guard boundary rule to prevent negative salary metrics
    if (prospectiveWorker.monthlySalary < 0.0) 
    {
        printf("Validation Failure: Resource compensation rates cannot be negative.\n");
        return;
    }

    // Copy temporary local record into the global structural array block safely
    staffRoster[activeStaffCount] = prospectiveWorker;
    activeStaffCount++;
    printf("Success: Employee record registered and synced.\n");
}

// Function displaying active data records in an aligned layout grid
void listActiveRoster() 
{
    if (activeStaffCount == 0) 
    {
        printf("Database Status: Roster directory tracks zero active profiles.\n");
        return;
    }

    printf("\n%-10s %-25s %-20s %-15s\n", "Emp ID", "Full Identity Name", "Role Designation", "Monthly Pay");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < activeStaffCount; i++) 
    {
        printf("%-10d %-25s %-20s INR %-11.2f\n", 
               staffRoster[i].employeeId, 
               staffRoster[i].fullName, 
               staffRoster[i].role, 
               staffRoster[i].monthlySalary);
    }
}

// Function tracking financial trend summaries across structural array indices
void computePayrollSummary() 
{
    if (activeStaffCount == 0) 
    {
        printf("Calculations Aborted: No workforce data profiles exist to audit.\n");
        return;
    }

    float totalPayrollExpense = 0.0;
    
    // Accumulate the operational sum values via continuous matrix index scans
    for (int i = 0; i < activeStaffCount; i++) 
    {
        totalPayrollExpense += staffRoster[i].monthlySalary;
    }

    float meanCompensation = totalPayrollExpense / activeStaffCount;

    printf("\n================ FINANCIAL SYSTEM REVIEWS ================\n");
    printf(" Total Active Employees Logged   : %d members\n", activeStaffCount);
    printf(" Total Combined Monthly Payroll  : INR %.2f\n", totalPayrollExpense);
    printf(" Mean Workforce Resource Payrate : INR %.2f\n", meanCompensation);
    printf("==========================================================\n");
}
