#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 150   //Write a program to Create library management system.
#define STR_LEN 50

// Structure representing an individual book item
typedef struct 
{
    int bookId;
    char title[STR_LEN];
    char author[STR_LEN];
    int isIssued; // 0 = Available inside Library, 1 = Issued/Checked out
} 
Book;

// Global system tracking state variables
Book libraryCatalog[MAX_BOOKS];
int activeBookCount = 0;

// Explicitly defined clean function prototypes
void presentLibraryMenu();
void registerNewBook();
void listLibraryInventory();
void locateBookByTitle();
void modifyBookIssueStatus();

int main() 
{
    int operationalChoice;

    while (1) 
    {
        presentLibraryMenu();
        printf("Enter your operational choice: ");
        
        // Defensive input verification 
        if (scanf("%d", &operationalChoice) != 1) 
        {
            printf("Error decoding numeric choices. Shutting down system interface.\n");
            break;
        }

        switch (operationalChoice) 
        {
            case 1:
                registerNewBook();
                break;
            case 2:
                listLibraryInventory();
                break;
            case 3:
                locateBookByTitle();
                break;
            case 4:
                modifyBookIssueStatus();
                break;
            case 5:
                printf("Closing Terminal Interface. System offline. Goodbye!\n");
                return 0;
            default:
                printf("Unassigned numeric index. Please input an integer 1 through 5.\n");
        }
    }
    return 0;
}

// Function to cleanly render user options
void presentLibraryMenu() 
{
    printf("\n============== ACADEMIC LIBRARY TERMINAL ==============\n");
    printf("1. Register a New Book Profile\n");
    printf("2. Display Complete Catalog Inventory\n");
    printf("3. Search Book Information by Title\n");
    printf("4. Update Issue / Return Status\n");
    printf("5. Shutdown Terminal Application\n");
    printf("=======================================================\n");
}

// Function to handle adding new materials safely to database structure bounds
void registerNewBook() 
{
    if (activeBookCount >= MAX_BOOKS) 
    {
        printf("Storage Fault: Maximum catalog volume limits reached.\n");
        return;
    }

    Book provisionalBook;
    printf("Assign Unique Book Accession ID: ");
    scanf("%d", &provisionalBook.bookId);

    // Stop identification clashes completely via lookup checks
    for (int i = 0; i < activeBookCount; i++) 
    {
        if (libraryCatalog[i].bookId == provisionalBook.bookId) 
        {
            printf("Conflict Error: Book Accession ID %d is already assigned.\n", provisionalBook.bookId);
            return;
        }
    }

    printf("Input Book Title: ");
    getchar(); // Clear structural stdin carriage buffers
    fgets(provisionalBook.title, STR_LEN, stdin);
    provisionalBook.title[strcspn(provisionalBook.title, "\n")] = 0; // Strip trailing space markers

    printf("Input Author Name: ");
    fgets(provisionalBook.author, STR_LEN, stdin);
    provisionalBook.author[strcspn(provisionalBook.author, "\n")] = 0;

    // By default newly added materials are set inside library availability matrix
    provisionalBook.isIssued = 0; 

    // Store into indexed system array elements
    libraryCatalog[activeBookCount] = provisionalBook;
    activeBookCount++;
    printf("Inventory Event: Material logged and stored safely.\n");
}

// Function displaying dynamic catalog layouts
void listLibraryInventory() 
{
    if (activeBookCount == 0) 
    {
        printf("Catalog Notice: Roster database tracks zero volumes.\n");
        return;
    }

    printf("\n%-10s %-25s %-20s %-15s\n", "ID Code", "Book Title", "Author", "Status Flag");
    printf("-----------------------------------------------------------------------------\n");
    for (int i = 0; i < activeBookCount; i++) 
    {
        printf("%-10d %-25s %-20s %-15s\n", 
               libraryCatalog[i].bookId, 
               libraryCatalog[i].title, 
               libraryCatalog[i].author, 
               (libraryCatalog[i].isIssued == 1) ? "Checked Out" : "In Library");
    }
}

// Function processing case-sensitive string matching routines
void locateBookByTitle() 
{
    if (activeBookCount == 0) 
    {
        printf("Search Cancelled: Empty tracking matrix catalog data.\n");
        return;
    }

    char queryingTitle[STR_LEN];
    printf("Input full text Book Title to match: ");
    getchar(); // Purge trailing return markers from previous frames
    fgets(queryingTitle, STR_LEN, stdin);
    queryingTitle[strcspn(queryingTitle, "\n")] = 0;

    for (int i = 0; i < activeBookCount; i++) 
    {
        // Safe string comparisons utilizing C standard libraries
        if (strcmp(libraryCatalog[i].title, queryingTitle) == 0) 
        {
            printf("\n--- Match Profile Located Inside Matrix ---\n");
            printf("Accession ID : %d\n", libraryCatalog[i].bookId);
            printf("Book Title   : %s\n", libraryCatalog[i].title);
            printf("Author Name  : %s\n", libraryCatalog[i].author);
            printf("Status info  : %s\n", (libraryCatalog[i].isIssued == 1) ? "Checked Out" : "In Library");
            printf("--------------------------------------------\n");
            return;
        }
    }
    printf("Query Failure: Title '%s' does not exist in the catalog indices.\n", queryingTitle);
}

// Function modifying structure parameters without breaking data integrity
void modifyBookIssueStatus() 
{
    if (activeBookCount == 0) 
    {
        printf("Operation Halt: Zero records to update.\n");
        return;
    }

    int targetedBookId;
    printf("Input Book ID code to toggle status: ");
    scanf("%d", &targetedBookId);

    for (int i = 0; i < activeBookCount; i++) 
    {
        if (libraryCatalog[i].bookId == targetedBookId) 
        {
            if (libraryCatalog[i].isIssued == 0) 
            {
                libraryCatalog[i].isIssued = 1;
                printf("Success: Book status altered to [Checked Out].\n");
            } 
            else 
            {
                libraryCatalog[i].isIssued = 0;
                printf("Success: Material returned safely to shelves. Status: [In Library].\n");
            }
            return;
        }
    }
    printf("Invalid Signature: Book ID code %d not matched inside current registers.\n", targetedBookId);
}
