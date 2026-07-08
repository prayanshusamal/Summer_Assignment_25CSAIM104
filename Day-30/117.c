#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100    //Write a program to Create student record system using arrays and strings.
#define NAME_LENGTH 50
#define COURSE_LENGTH 30

// Structure definition utilizing arrays and strings for student attributes
typedef struct 
{
    int rollNumber;
    char fullName[NAME_LENGTH];
    char course[COURSE_LENGTH];
    float marks;
} 
Student;

// Global memory tracker array
Student studentRoster[MAX_STUDENTS];
int currentStudentCount = 0;

// Explicit clean function prototypes
void displaySystemMenu();
void insertStudentRecord();
void displayAllRecords();
void searchStudentByName();

int main() 
{
    int systemOption;

    while (1) 
    {
        displaySystemMenu();
        printf("Select active operation index: ");
        
        // Defensive input verification check for menu choices
        if (scanf("%d", &systemOption) != 1) 
        {
            printf("Error reading system integer format. Forcing application shutdown.\n");
            break;
        }

        switch (systemOption) 
        {
            case 1:
                insertStudentRecord();
                break;
            case 2:
                displayAllRecords();
                break;
            case 3:
                searchStudentByName();
                break;
            case 4:
                printf("Saving registry data states. System offline. Goodbye!\n");
                return 0;
            default:
                printf("Operation index not recognized. Please enter an integer from 1 to 4.\n");
        }
    }
    return 0;
}

// Function to print available menu choices cleanly
void displaySystemMenu() 
{
    printf("\n============== ACADEMIC STUDENT REGISTRY ==============\n");
    printf("1. Register a New Student Record\n");
    printf("2. List All Registered Records\n");
    printf("3. Search Student Records by Name\n");
    printf("4. Shutdown Registry Terminal\n");
    printf("=======================================================\n");
}

// Function managing input strings and integer bounds to populate structural blocks safely
void insertStudentRecord() 
{
    if (currentStudentCount >= MAX_STUDENTS) 
    {
        printf("Registry Fault: Maximum database registration thresholds reached.\n");
        return;
    }

    Student prospectiveStudent;
    printf("Assign Unique Roll Number: ");
    scanf("%d", &prospectiveStudent.rollNumber);

    // Verify Roll Number uniqueness to block duplicate registry tracks
    for (int i = 0; i < currentStudentCount; i++) 
    {
        if (studentRoster[i].rollNumber == prospectiveStudent.rollNumber) 
        {
            printf("Conflict Error: Roll Number %d already exists inside indices.\n", prospectiveStudent.rollNumber);
            return;
        }
    }

    printf("Enter Student Full Name: ");
    getchar(); // Purge trailing newline character pipelines from previous numeric input
    fgets(prospectiveStudent.fullName, NAME_LENGTH, stdin);
    prospectiveStudent.fullName[strcspn(prospectiveStudent.fullName, "\n")] = 0; // Strip trailing space line feeds

    printf("Enter Assigned Course Name: ");
    fgets(prospectiveStudent.course, COURSE_LENGTH, stdin);
    prospectiveStudent.course[strcspn(prospectiveStudent.course, "\n")] = 0;

    printf("Enter Secured Academic Marks (0.0 to 100.0): ");
    scanf("%f", &prospectiveStudent.marks);
    
    // Boundary check validation to prevent out-of-scale grading scores
    if (prospectiveStudent.marks < 0.0 || prospectiveStudent.marks > 100.0) 
    {
        printf("Validation Failure: Academic score matrix must fall between 0.0 and 100.0.\n");
        return;
    }

    // Save newly populated local record into the global structural array block
    studentRoster[currentStudentCount] = prospectiveStudent;
    currentStudentCount++;
    printf("Success: Student record securely logged and synced.\n");
}

// Function showcasing complete records formatted into an aligned tabular grid
void displayAllRecords() 
{
    if (currentStudentCount == 0) 
    {
        printf("Registry Status: Database tracks zero active student volumes.\n");
        return;
    }

    printf("\n%-10s %-25s %-20s %-7s\n", "Roll No.", "Full Student Name", "Enrolled Course", "Marks");
    printf("----------------------------------------------------------------------------\n");
    for (int i = 0; i < currentStudentCount; i++) 
    {
        printf("%-10d %-25s %-20s %-7.2f\n", 
               studentRoster[i].rollNumber, 
               studentRoster[i].fullName, 
               studentRoster[i].course, 
               studentRoster[i].marks);
    }
}

// Function performing exact string match searches across array indices
void searchStudentByName() 
{
    if (currentStudentCount == 0) 
    {
        printf("Search Aborted: Empty data matrix directory indices.\n");
        return;
    }

    char querySearchName[NAME_LENGTH];
    printf("Enter string text Full Name to match: ");
    getchar(); // Flush stream path buffers
    fgets(querySearchName, NAME_LENGTH, stdin);
    querySearchName[strcspn(querySearchName, "\n")] = 0;

    for (int i = 0; i < currentStudentCount; i++) 
    {
        // String comparison utilizing C string libraries safely
        if (strcmp(studentRoster[i].fullName, querySearchName) == 0) 
        {
            printf("\n--- Profile Record Match Located Inside Index ---\n");
            printf("Roll Number: %d\n", studentRoster[i].rollNumber);
            printf("Full Name  : %s\n", studentRoster[i].fullName);
            printf("Course     : %s\n", studentRoster[i].course);
            printf("Score Marks: %.2f\n", studentRoster[i].marks);
            printf("--------------------------------------------------\n");
            return;
        }
    }
    printf("Query Failure: Profile name '%s' was not matched inside system loops.\n", querySearchName);
}
