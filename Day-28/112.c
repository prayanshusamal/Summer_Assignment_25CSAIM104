#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100    //Write a program to Create contact management system.
#define STR_SIZE 50

// Structure representing an individual contact card profile
typedef struct 
{
    char fullName[STR_SIZE];
    char phoneNumber[STR_SIZE];
    char emailAddress[STR_SIZE];
} 
Contact;

// Global directory data index array 
Contact addressBook[MAX_CONTACTS];
int totalContactsCount = 0;

// Explicitly defined clean function prototypes
void renderContactMenu();
void insertNewContact();
void listCompleteDirectory();
void searchContactByName();
void eraseContactRecord();

int main() 
{
    int operationalChoice;

    while (1) 
    {
        renderContactMenu();
        printf("Select dynamic directory choice: ");
        
        // Defensive input verification 
        if (scanf("%d", &operationalChoice) != 1) 
        {
            printf("Error matching numeric menu structures. Halting application framework.\n");
            break;
        }

        switch (operationalChoice) 
        {
            case 1:
                insertNewContact();
                break;
            case 2:
                listCompleteDirectory();
                break;
            case 3:
                searchContactByName();
                break;
            case 4:
                eraseContactRecord();
                break;
            case 5:
                printf("Saving database changes to memory. System closing safely!\n");
                return 0;
            default:
                printf("Index matching error. Please input an integer ranging 1 to 5.\n");
        }
    }
    return 0;
}

// Function to print available database system choices cleanly
void renderContactMenu() 
{
    printf("\n============== CORE DIRECTORY SYSTEM ==============\n");
    printf("1. Create and Save New Contact Profile\n");
    printf("2. List All Active Address Book Cards\n");
    printf("3. Search Contact Details by Name\n");
    printf("4. Erase Single Contact from Database\n");
    printf("5. Exit Directory Application\n");
    printf("===================================================\n");
}

// Function managing input strings safely to add parameters inside boundaries
void insertNewContact() 
{
    if (totalContactsCount >= MAX_CONTACTS) 
    {
        printf("Memory Warning: Maximum address book directory capacity limits reached.\n");
        return;
    }

    Contact newContactCard;
    printf("Enter Contact Full Name: ");
    getchar(); // Clear remaining carriage line returns from stdin streams
    fgets(newContactCard.fullName, STR_SIZE, stdin);
    newContactCard.fullName[strcspn(newContactCard.fullName, "\n")] = 0; // Strip trailing space markers

    // Enforce name checks to block exact name duplication errors inside directory lists
    for (int i = 0; i < totalContactsCount; i++) 
    {
        if (strcmp(addressBook[i].fullName, newContactCard.fullName) == 0) 
        {
            printf("Duplicate Blocked: Profiles with identity matching '%s' already exist.\n", newContactCard.fullName);
            return;
        }
    }

    printf("Enter Phone Number: ");
    fgets(newContactCard.phoneNumber, STR_SIZE, stdin);
    newContactCard.phoneNumber[strcspn(newContactCard.phoneNumber, "\n")] = 0;

    printf("Enter Email Address: ");
    fgets(newContactCard.emailAddress, STR_SIZE, stdin);
    newContactCard.emailAddress[strcspn(newContactCard.emailAddress, "\n")] = 0;

    // Sync instance value directly into specific array element index
    addressBook[totalContactsCount] = newContactCard;
    totalContactsCount++;
    printf("Success: Contact linked and saved inside memory registry.\n");
}

// Function generating clean table layouts for cataloged items
void listCompleteDirectory() 
{
    if (totalContactsCount == 0) 
    {
        printf("Directory Status: Zero data records found inside index loops.\n");
        return;
    }

    printf("\n%-25s %-20s %-30s\n", "Contact Full Identity", "Phone Number", "Email Address");
    printf("-------------------------------------------------------------------------------------\n");
    for (int i = 0; i < totalContactsCount; i++) 
    {
        printf("%-25s %-20s %-30s\n", 
               addressBook[i].fullName, 
               addressBook[i].phoneNumber, 
               addressBook[i].emailAddress);
    }
}

// Function searching database using pure library string operations
void searchContactByName() 
{
    if (totalContactsCount == 0) 
    {
        printf("Search Aborted: Registry structure contains no profile entities.\n");
        return;
    }

    char targetSearchName[STR_SIZE];
    printf("Enter complete Full Name to search: ");
    getchar(); // Clear stray system pipeline buffers
    fgets(targetSearchName, STR_SIZE, stdin);
    targetSearchName[strcspn(targetSearchName, "\n")] = 0;

    for (int i = 0; i < totalContactsCount; i++) 
    {
        if (strcmp(addressBook[i].fullName, targetSearchName) == 0) 
        {
            printf("\n--- Directory Match Profile Found ---\n");
            printf("Full Name     : %s\n", addressBook[i].fullName);
            printf("Phone Number  : %s\n", addressBook[i].phoneNumber);
            printf("Email Address : %s\n", addressBook[i].emailAddress);
            printf("--------------------------------------\n");
            return;
        }
    }
    printf("Query Failure: Match string profile '%s' does not exist inside index trackers.\n", targetSearchName);
}

// Function processing shifting logic cleanly to delete records without splitting indices
void eraseContactRecord() 
{
    if (totalContactsCount == 0) 
    {
        printf("Erase Action Denied: Database matrix is completely empty.\n");
        return;
    }

    char targetingEraseName[STR_SIZE];
    printf("Enter target Contact Full Name to erase: ");
    getchar(); // Flush stream paths
    fgets(targetingEraseName, STR_SIZE, stdin);
    targetingEraseName[strcspn(targetingEraseName, "\n")] = 0;

    int matchPositionIndex = -1;
    for (int i = 0; i < totalContactsCount; i++) 
    {
        if (strcmp(addressBook[i].fullName, targetingEraseName) == 0) 
        {
            matchPositionIndex = i;
            break;
        }
    }

    if (matchPositionIndex == -1) 
    {
        printf("Identity Match Error: Profile named '%s' was not located inside listings.\n", targetingEraseName);
        return;
    }

    // Overwrite the removed record by shifting left all following array blocks 
    for (int i = matchPositionIndex; i < totalContactsCount - 1; i++) 
    {
        addressBook[i] = addressBook[i + 1];
    }
    
    totalContactsCount--;
    printf("Success: Directory details for '%s' were cleanly purged.\n", targetingEraseName);
}
