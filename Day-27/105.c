#include <string.h>

#define MAX_STUDENTS 100      //Write a program to Create student record management system.
#include <stdio.h>
#define NAME_LENGTH 50

// Structure to hold student details
typedef struct 
{
    int id;
    char name[NAME_LENGTH];
    float gpa;
} 
Student;

// Global array and counter to manage records
Student records[MAX_STUDENTS];
int studentCount = 0;

// Function prototypes
void menu();
void addStudent();
void displayStudents();
void searchStudent();
void deleteStudent();

int main() 
{
    int choice;

    while (1) 
    {
        menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) 
        {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) 
        {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void menu() 
{
    printf("\n=== Student Record Management System ===\n");
    printf("1. Add Student Record\n");
    printf("2. Display All Student Records\n");
    printf("3. Search Student by ID\n");
    printf("4. Delete Student Record\n");
    printf("5. Exit\n");
    printf("========================================\n");
}

// Function to add a new student record
void addStudent() 
{
    if (studentCount >= MAX_STUDENTS) 
    {
        printf("Error: System storage is full!\n");
        return;
    }

    Student s;
    printf("Enter Student ID: ");
    scanf("%d", &s.id);

    // Check if ID already exists
    for (int i = 0; i < studentCount; i++)
    {
        if (records[i].id == s.id) 
        {
            printf("Error: Student with ID %d already exists.\n", s.id);
            return;
        }
    }

    printf("Enter Student Name: ");
    getchar(); // Clear the newline buffer
    fgets(s.name, NAME_LENGTH, stdin);
    s.name[strcspn(s.name, "\n")] = 0; // Remove trailing newline

    printf("Enter Student GPA: ");
    scanf("%f", &s.gpa);

    records[studentCount] = s;
    studentCount++;
    printf("Record added successfully!\n");
}

// Function to display all student records
void displayStudents() 
{
    if (studentCount == 0) 
    {
        printf("No records found.\n");
        return;
    }

    printf("\n%-10s %-30s %-5s\n", "ID", "Name", "GPA");
    printf("------------------------------------------------\n");

    for (int i = 0; i < studentCount; i++) 
    {
        printf("%-10d %-30s %-5.2f\n", records[i].id, records[i].name, records[i].gpa);
    }
}

// Function to search for a student by ID
void searchStudent() 
{
    if (studentCount == 0) 
    {
        printf("No records available to search.\n");
        return;
    }

    int searchId;
    printf("Enter Student ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < studentCount; i++) 
    {
        if (records[i].id == searchId) 
        {
            printf("\nRecord Found:\n");
            printf("ID: %d\n", records[i].id);
            printf("Name: %s\n", records[i].name);
            printf("GPA: %.2f\n", records[i].gpa);
            return;
        }
    }
    printf("Student with ID %d not found.\n", searchId);
}

// Function to delete a student record by ID
void deleteStudent() 
{
    if (studentCount == 0) 
    {
        printf("No records available to delete.\n");
        return;
    }

    int deleteId;
    printf("Enter Student ID to delete: ");
    scanf("%d", &deleteId);

    int foundIndex = -1;
    for (int i = 0; i < studentCount; i++) 
    {
        if (records[i].id == deleteId) 
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) 
    {
        printf("Student with ID %d not found.\n", deleteId);
        return;
    }

    // Shift remaining elements to fill the gap
    for (int i = foundIndex; i < studentCount - 1; i++) 
    {
        records[i] = records[i + 1];
    }
    studentCount--;
    printf("Record deleted successfully!\n");
}
