#include <stdio.h>
#include <string.h>

#define MAX_CARS 50      //Write a program to Develop complete mini project using arrays, strings and functions.
#define STR_LEN 50

// Structure representing an individual vehicle unit
typedef struct 
{
    int carId;
    char modelName[STR_LEN];
    char licensePlate[STR_LEN];
    double pricePerDay;
    int isRented; // 0 = Available, 1 = Rented Out
} 
Vehicle;

// Global array structure and state counter
Vehicle fleet[MAX_CARS];
int totalCarCount = 0;

// Explicit clean function prototypes
void displaySystemMenu();
void registerNewVehicle();
void listFleetInventory();
void processCarRental();
void processCarReturn();

int main() 
{
    int systemChoice;

    while (1) 
    {
        displaySystemMenu();
        printf("Select operational choice index: ");

        // Defensive input verification check for menu choices
        if (scanf("%d", &systemChoice) != 1) 
        {
            printf("Error reading system integer format. Forcing application termination.\n");
            break;
        }

        switch (systemChoice) 
        {
            case 1:
                registerNewVehicle();
                break;
            case 2:
                listFleetInventory();
                break;
            case 3:
                processCarRental();
                break;
            case 4:
                processCarReturn();
                break;
            case 5:
                printf("Saving system state to memory. Fleet console offline. Goodbye!\n");
                return 0;
            default:
                printf("Operation index not recognized. Please input an integer from 1 to 5.\n");
        }
    }
    return 0;
}

// Function to print available menu choices cleanly
void displaySystemMenu() 
{
    printf("\n============== FLEET RENTAL MANAGEMENT SYSTEM ==============\n");
    printf("1. Register a New Vehicle to Fleet\n");
    printf("2. List All Active Fleet Vehicles\n");
    printf("3. Process Car Rental Out (Check-Out)\n");
    printf("4. Process Car Return & Billing (Check-In)\n");
    printf("5. Shutdown Terminal Console\n");
    printf("============================================================\n");
}

// Function managing input strings and bounds to register vehicles safely
void registerNewVehicle() 
{
    if (totalCarCount >= MAX_CARS) 
    {
        printf("Fleet Fault: Maximum garage storage thresholds reached.\n");
        return;
    }

    Vehicle prospectiveCar;
    printf("Assign Unique Car ID Code: ");
    scanf("%d", &prospectiveCar.carId);

    // Verify ID uniqueness to block catalog identifier clashes
    for (int i = 0; i < totalCarCount; i++) 
    {
        if (fleet[i].carId == prospectiveCar.carId) 
        {
            printf("Conflict Error: Car ID Code %d is already registered.\n", prospectiveCar.carId);
            return;
        }
    }

    printf("Enter Car Model Description: ");
    getchar(); // Purge trailing newline characters out of stream pipelines
    fgets(prospectiveCar.modelName, STR_LEN, stdin);
    prospectiveCar.modelName[strcspn(prospectiveCar.modelName, "\n")] = 0; // Strip trailing space lines

    printf("Enter Vehicle License Plate Number: ");
    fgets(prospectiveCar.licensePlate, STR_LEN, stdin);
    prospectiveCar.licensePlate[strcspn(prospectiveCar.licensePlate, "\n")] = 0;

    printf("Set Daily Rental Cost Rate: INR ");
    scanf("%lf", &prospectiveCar.pricePerDay);

    if (prospectiveCar.pricePerDay <= 0.0) 
    {
        printf("Validation Failure: Rental price metrics must be greater than zero.\n");
        return;
    }

    // Default status state is set inside available fleet indices
    prospectiveCar.isRented = 0;

    // Save temporary local data structure directly into global tracking array elements
    fleet[totalCarCount] = prospectiveCar;
    totalCarCount++;
    printf("Success: Vehicle profile successfully synced into fleet registers.\n");
}

// Function showcasing complete records formatted into an aligned tabular grid
void listFleetInventory() 
{
    if (totalCarCount == 0) 
    {
        printf("Inventory Status: Fleet registry tracks zero registered vehicles.\n");
        return;
    }

    printf("\n%-8s %-25s %-20s %-15s %-12s\n", "Car ID", "Model Description", "License Plate", "Daily Rate", "Current State");
    printf("-------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < totalCarCount; i++) 
    {
        printf("%-8d %-25s %-20s INR %-11.2f %-12s\n", 
               fleet[i].carId, 
               fleet[i].modelName, 
               fleet[i].licensePlate, 
               fleet[i].pricePerDay,
               (fleet[i].isRented == 1) ? "Rented Out" : "Available");
    }
}

// Function modifying structure parameters to execute customer rental bookings
void processCarRental() 
{
    if (totalCarCount == 0) 
    {
        printf("Operation Aborted: Fleet registry is completely empty.\n");
        return;
    }

    int targetId;
    printf("Enter Car ID Code to rent: ");
    scanf("%d", &targetId);

    for (int i = 0; i < totalCarCount; i++) 
    {
        if (fleet[i].carId == targetId) 
        {
            // Guard clause checking if vehicle is out on rental duties
            if (fleet[i].isRented == 1) 
            {
                printf("Transaction Denied: Vehicle is currently rented out to another profile.\n");
                return;
            }

            fleet[i].isRented = 1;
            printf("Success: Checkout processed! Vehicle %s is now marked [Rented Out].\n", fleet[i].modelName);
            return;
        }
    }
    printf("Search Error: Car ID Code %d not matched in current inventory trackers.\n", targetId);
}

// Function evaluating financial cost and releasing states safely back to baseline thresholds
void processCarReturn() 
{
    if (totalCarCount == 0) 
    {
        printf("Operation Aborted: Zero elements active inside tracking matrices.\n");
        return;
    }

    int targetId, rentalDays;
    double totalBillAmount;

    printf("Enter Car ID Code being returned: ");
    scanf("%d", &targetId);

    for (int i = 0; i < totalCarCount; i++) 
    {
        if (fleet[i].carId == targetId) 
        {
            // Guard condition validating if vehicle was checked out
            if (fleet[i].isRented == 0) 
            {
                printf("Notice: Car is already parked in the garage and marked [Available].\n");
                return;
            }

            printf("Enter total number of active rental days: ");
            scanf("%d", &rentalDays);

            if (rentalDays <= 0) 
            {
                printf("Transaction Aborted: Days must be an integer count greater than zero.\n");
                return;
            }

            // Mathematical calculation logic passing structure attributes cleanly
            totalBillAmount = fleet[i].pricePerDay * rentalDays;
            fleet[i].isRented = 0; // Release status flag back to default configuration

            printf("\n================ INVOICE GENERATED ================\n");
            printf(" Vehicle Model   : %s\n", fleet[i].modelName);
            printf(" License Plate   : %s\n", fleet[i].licensePlate);
            printf(" Days Charged    : %d Days\n", rentalDays);
            printf(" Total Rent Due  : INR %.2f\n", totalBillAmount);
            printf("===================================================\n");
            printf("Status Event: Return processed. Vehicle is now [Available].\n");
            return;
        }
    }
    printf("Search Error: Car ID Code %d not registered in active inventory rosters.\n", targetId);
}
