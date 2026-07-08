#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 50        //Write a program to Create mini library system.
#define STR_BOUND 50

// Structure representing an individual library book profile
typedef struct 
{
    int bookId;
    char title[STR_BOUND];
    char author[STR_BOUND];
    int isBorrowed; // 0 = Available on shelf, 1 = Borrowed out
} 
MiniBook;

// Global catalog arrays
MiniBook libraryShelf[MAX_BOOKS];
int totalBooksCount = 0;

// Explicit clean function prototypes
void displayMiniLibraryMenu();
void insertBookProfile();
void displayShelfInventory();
void borrowBookAction();
void returnBookAction();

int main() 
{
    int interfaceChoice;

    while (1) 
    {
        displayMiniLibraryMenu();
        printf("Select active library option: ");
        
        // Defensive input verification check for menu values
        if (scanf("%d", &interfaceChoice) != 1) 
        {
            printf("Error reading numeric choices. Halting terminal process flow.\n");
            break;
        }

        switch (interfaceChoice) 
        {
            case 1:
                insertBookProfile();
                break;
            case 2:
                displayShelfInventory();
                break;
            case 3:
                borrowBookAction();
                break;
            case 4:
                returnBookAction();
                break;
            case 5:
                printf("Closing Mini Library terminal connection. Catalog secure. Goodbye!\n");
                return 0;
            default:
                printf("Operation code unassigned. Input an integer ranging 1 to 5.\n");
        }
    }
    return 0;
}

// Function to print available operation choices cleanly
void displayMiniLibraryMenu() 
{
    printf("\n============== MINI LIBRARY WORKSPACE ==============\n");
    printf("1. Add a New Book to the Shelf\n");
    printf("2. View Current Shelf Inventory Listings\n");
    printf("3. Borrow a Book (Check Out)\n");
    printf("4. Return a Book (Check In)\n");
    printf("5. Shutdown Library Application\n");
    printf("====================================================\n");
}

// Function managing input loops to append parameters inside array bounds safely
void insertBookProfile() 
{
    if (totalBooksCount >= MAX_BOOKS) 
    {
        printf("Storage Fault: Mini library shelving capacity limit reached.\n");
        return;
    }

    MiniBook incomingBook;
    printf("Assign Unique Book ID Code: ");
    scanf("%d", &incomingBook.bookId);

    // Verify ID uniqueness to block catalog collisions
    for (int i = 0; i < totalBooksCount; i++) 
    {
        if (libraryShelf[i].bookId == incomingBook.bookId) 
        {
            printf("Conflict Error: Book ID Code %d already registered.\n", incomingBook.bookId);
            return;
        }
    }

    printf("Enter Book Title: ");
    getchar(); // Clear remaining line feed characters from previous numeric input
    fgets(incomingBook.title, STR_BOUND, stdin);
    incomingBook.title[strcspn(incomingBook.title, "\n")] = 0; // Strip trailing space markers

    printf("Enter Author Name: ");
    fgets(incomingBook.author, STR_BOUND, stdin);
    incomingBook.author[strcspn(incomingBook.author, "\n")] = 0;

    // Set newborn profile state defaults to on-shelf availability matrix
    incomingBook.isBorrowed = 0;

    // Sync structural object data directly into the sequential tracking array index
    libraryShelf[totalBooksCount] = incomingBook;
    totalBooksCount++;
    printf("Success: Material logged and added to shelf records.\n");
}

// Function displaying current database fields in a clean tabular grid
void displayShelfInventory() 
{
    if (totalBooksCount == 0) 
    {
        printf("Inventory Status: Shelf trackers locate zero materials.\n");
        return;
    }

    printf("\n%-10s %-25s %-20s %-15s\n", "Book ID", "Book Title", "Author Identity", "Current State");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < totalBooksCount; i++) 
    {
        printf("%-10d %-25s %-20s %-15s\n", 
               libraryShelf[i].bookId, 
               libraryShelf[i].title, 
               libraryShelf[i].author, 
               (libraryShelf[i].isBorrowed == 1) ? "Borrowed" : "Available");
    }
}

// Function updating array properties securely to handle borrow updates
void borrowBookAction() 
{
    if (totalBooksCount == 0) 
    {
        printf("Borrow Aborted: No active library volumes initialized.\n");
        return;
    }

    int targetedId;
    printf("Enter Book ID to borrow: ");
    scanf("%d", &targetedId);

    for (int i = 0; i < totalBooksCount; i++) 
    {
        if (libraryShelf[i].bookId == targetedId) 
        {
            // Guard loop to protect against double borrowing collisions
            if (libraryShelf[i].isBorrowed == 1) 
            {
                printf("Transaction Denied: Book is already checked out by another profile.\n");
                return;
            }

            libraryShelf[i].isBorrowed = 1;
            printf("Success: Book checkout finalized. Status updated to [Borrowed].\n");
            return;
        }
    }
    printf("Search Error: Book ID Code %d not matched in inventory registers.\n", targetedId);
}

// Function checking boundaries and updating variables to process library returns
void returnBookAction() 
{
    if (totalBooksCount == 0) 
    {
        printf("Return Aborted: System contains zero logged elements.\n");
        return;
    }

    int targetedId;
    printf("Enter Book ID to return: ");
    scanf("%d", &targetedId);

    for (int i = 0; i < totalBooksCount; i++) 
    {
        if (libraryShelf[i].bookId == targetedId) 
        {
            // Guard clause checking if material was actually out
            if (libraryShelf[i].isBorrowed == 0) 
            {
                printf("Notice: Book is already on the shelf and marked [Available].\n");
                return;
            }

            libraryShelf[i].isBorrowed = 0;
            printf("Success: Material returned safely to shelves. Status: [Available].\n");
            return;
        }
    }
    printf("Search Error: Book ID Code %d not matched in current catalog rankings.\n", targetedId);
}
