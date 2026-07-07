#include <stdio.h>

#define MAX_CAPACITY 100    //Write a program to Create menu-driven array operations system.

// Explicit clean function prototypes
void displayArrayMenu();
void printArray(int arr[], int size);
void insertElement(int arr[], int *size);
void deleteElement(int arr[], int *size);
void searchElement(int arr[], int size);

int main() 
{
    int mainArray[MAX_CAPACITY];
    int currentSize = 0;
    int userOption;

    while (1) 
    {
        displayArrayMenu();
        printf("Select active array operation index: ");
        
        // Defensive input verification check for option values
        if (scanf("%d", &userOption) != 1) 
        {
            printf("Error decoding numeric choice formats. Terminating engine interface.\n");
            break;
        }

        switch (userOption) 
        {
            case 1:
                printArray(mainArray, currentSize);
                break;
            case 2:
                insertElement(mainArray, &currentSize);
                break;
            case 3:
                deleteElement(mainArray, &currentSize);
                break;
            case 4:
                searchElement(mainArray, currentSize);
                break;
            case 5:
                printf("Closing Matrix Workspace Data Pipelines. System offline. Goodbye!\n");
                return 0;
            default:
                printf("Operation code unassigned. Input an integer ranging 1 to 5.\n");
        }
    }
    return 0;
}

// Function to print the available user system choices cleanly
void displayArrayMenu() 
{
    printf("\n============== MATRIX OPERATION ARRAYS ==============\n");
    printf("1. View Current Array Elements State\n");
    printf("2. Insert a New Element at Specific Index\n");
    printf("3. Delete an Element from Specific Index\n");
    printf("4. Linear Search for an Element Value\n");
    printf("5. Exit Matrix Workspace Environment\n");
    printf("=====================================================\n");
}

// Function printing memory values cleanly inside visual bounds
void printArray(int arr[], int size) 
{
    if (size == 0) 
    {
        printf("\nArray Status Notice: Structure is completely empty [ ].\n");
        return;
    }

    printf("\nActive Array States: [ ");
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("]\nTotal Count Tracking: %d Elements active.\n", size);
}

// Function managing shift routines to inject values into explicit bounds
void insertElement(int arr[], int *size) 
{
    if (*size >= MAX_CAPACITY) 
    {
        printf("Insertion Fault: Absolute tracking limit maximum of %d items reached.\n", MAX_CAPACITY);
        return;
    }

    int specifiedIndex, targetValue;
    printf("Enter target layout Index to insert at (0 to %d): ", *size);
    scanf("%d", &specifiedIndex);

    // Block boundary breaking out-of-index anomalies safely
    if (specifiedIndex < 0 || specifiedIndex > *size) 
    {
        printf("Boundary Crash Warning: Index value out of current structural range.\n");
        return;
    }

    printf("Enter new Integer value to inject: ");
    scanf("%d", &targetValue);

    // Shift memory elements towards the right to make an open space index slot
    for (int i = *size; i > specifiedIndex; i--) 
    {
        arr[i] = arr[i - 1];
    }

    // Insert data parameter at the calculated address index
    arr[specifiedIndex] = targetValue;
    (*size)++; // Update state size count globally
    printf("Success: Array values updated. Element injected into Index %d.\n", specifiedIndex);
}

// Function managing left-shifting logic to compress remaining spaces safely
void deleteElement(int arr[], int *size) 
{
    if (*size == 0) 
    {
        printf("Deletion Fault: Operation skipped, target matrix structure is empty.\n");
        return;
    }

    int targetDeletionIndex;
    printf("Enter specific Index to purge from (0 to %d): ", *size - 1);
    scanf("%d", &targetDeletionIndex);

    // Protect boundary thresholds 
    if (targetDeletionIndex < 0 || targetDeletionIndex >= *size) 
    {
        printf("Boundary Crash Warning: Target index does not exist inside parameters.\n");
        return;
    }

    int droppedValue = arr[targetDeletionIndex];

    // Close mid-list gaps by copying following blocks towards the left
    for (int i = targetDeletionIndex; i < *size - 1; i++) 
    {
        arr[i] = arr[i + 1];
    }

    (*size)--; // Update tracker counts
    printf("Success: Removed item value %d cleanly out of Index %d.\n", droppedValue, targetDeletionIndex);
}

// Function performing scanning sweeps inside array blocks
void searchElement(int arr[], int size) 
{
    if (size == 0) 
    {
        printf("Search Aborted: Empty data matrix structures.\n");
        return;
    }

    int queryMatchValue;
    printf("Enter target Integer value to look up: ");
    scanf("%d", &queryMatchValue);

    // Linear scanning routine across sequentially bound pointers
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == queryMatchValue) 
        {
            printf("Success: Value match discovered inside memory array block at Index: %d\n", i);
            return;
        }
    }
    printf("Query Failure: Value %d was not found inside database indexes.\n", queryMatchValue);
}
