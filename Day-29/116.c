#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100        //Write a program to Create inventory management system.
#define NAME_LIMIT 50

// Structure representing an individual product item
typedef struct 
{
    int productId;
    char productName[NAME_LIMIT];
    int quantity;
    double price;
} 
Product;

// Global warehouse ledger matrix array
Product warehouseStock[MAX_ITEMS];
int totalItemsCount = 0;

// Explicitly defined clean function prototypes
void displayInventoryMenu();
void addNewProduct();
void listActiveInventory();
void searchProductById();
void modifyStockQuantity();

int main() 
{
    int userOption;

    while (1) 
    {
        displayInventoryMenu();
        printf("Select active inventory operation: ");
        
        // Defensive input validation check for menu options
        if (scanf("%d", &userOption) != 1) 
        {
            printf("Error reading system integers. Shutting down warehouse terminal.\n");
            break;
        }

        switch (userOption) 
        {
            case 1:
                addNewProduct();
                break;
            case 2:
                listActiveInventory();
                break;
            case 3:
                searchProductById();
                break;
            case 4:
                modifyStockQuantity();
                break;
            case 5:
                printf("Saving inventory state. Warehouse database offline. Goodbye!\n");
                return 0;
            default:
                printf("Operation code unassigned. Please input an integer from 1 to 5.\n");
        }
    }
    return 0;
}

// Function to print available warehouse choices cleanly
void displayInventoryMenu() 
{
    printf("\n============== WAREHOUSE INVENTORY CORE ==============\n");
    printf("1. Register a New Product Profile\n");
    printf("2. List All Active Stock Inventories\n");
    printf("3. Search Product Information by ID\n");
    printf("4. Update Item Stock Quantity (Restock/Sale)\n");
    printf("5. Disconnect System Interface\n");
    printf("======================================================\n");
}

// Function to add a unique product to memory safely
void addNewProduct() 
{
    if (totalItemsCount >= MAX_ITEMS) 
    {
        printf("Storage Fault: Maximum warehouse storage thresholds reached.\n");
        return;
    }

    Product prospectiveItem;
    printf("Assign Unique Product ID: ");
    scanf("%d", &prospectiveItem.productId);

    // Verify ID uniqueness to block duplicate stock codes
    for (int i = 0; i < totalItemsCount; i++) 
    {
        if (warehouseStock[i].productId == prospectiveItem.productId) 
        {
            printf("Conflict Error: Product ID %d is already registered.\n", prospectiveItem.productId);
            return;
        }
    }

    printf("Enter Product Name: ");
    getchar(); // Clear trailing newline characters out of stream pipelines
    fgets(prospectiveItem.productName, NAME_LIMIT, stdin);
    prospectiveItem.productName[strcspn(prospectiveItem.productName, "\n")] = 0; // Strip trailing line feeds

    printf("Enter Initial Quantity: ");
    scanf("%d", &prospectiveItem.quantity);
    if (prospectiveItem.quantity < 0) 
    {
        printf("Validation Error: Initial stock quantity cannot be negative.\n");
        return;
    }

    printf("Enter Unit Price: INR ");
    scanf("%lf", &prospectiveItem.price);
    if (prospectiveItem.price < 0.0) 
    {
        printf("Validation Error: Product pricing metrics cannot be negative.\n");
        return;
    }

    // Save item parameters inside the tracked array memory index
    warehouseStock[totalItemsCount] = prospectiveItem;
    totalItemsCount++;
    printf("Success: Product profile synced into ledger records.\n");
}

// Function displaying formatted catalog lists cleanly
void listActiveInventory() 
{
    if (totalItemsCount == 0) 
    {
        printf("Inventory Status: Database tracks zero registered volumes.\n");
        return;
    }

    printf("\n%-10s %-25s %-12s %-15s\n", "Prod ID", "Product Description", "In Stock", "Unit Price");
    printf("------------------------------------------------------------------------\n");
    for (int i = 0; i < totalItemsCount; i++) 
    {
        printf("%-10d %-25s %-12d INR %-11.2f\n", 
               warehouseStock[i].productId, 
               warehouseStock[i].productName, 
               warehouseStock[i].quantity, 
               warehouseStock[i].price);
    }
}

// Function searching database using exact integer lookups
void searchProductById() 
{
    if (totalItemsCount == 0) 
    {
        printf("Search Aborted: Core tracking ledger matrix is empty.\n");
        return;
    }

    int targetedId;
    printf("Enter Product ID to locate: ");
    scanf("%d", &targetedId);

    for (int i = 0; i < totalItemsCount; i++) 
    {
        if (warehouseStock[i].productId == targetedId) 
        {
            printf("\n--- Product Profile Located Inside Ledger ---\n");
            printf("Product ID   : %d\n", warehouseStock[i].productId);
            printf("Description  : %s\n", warehouseStock[i].productName);
            printf("Current Stock: %d units\n", warehouseStock[i].quantity);
            printf("Unit Price   : INR %.2f\n", warehouseStock[i].price);
            printf("---------------------------------------------\n");
            return;
        }
    }
    printf("Query Failure: Product ID %d is not found inside current registers.\n", targetedId);
}

// Function modifying stock totals with protection boundaries against empty counts
void modifyStockQuantity() 
{
    if (totalItemsCount == 0) 
    {
        printf("Operation Halt: Zero available elements to modify.\n");
        return;
    }

    int targetedId, updateChoice, volumeChange;
    printf("Enter Product ID to adjust stock: ");
    scanf("%d", &targetedId);

    for (int i = 0; i < totalItemsCount; i++) 
    {
        if (warehouseStock[i].productId == targetedId) 
        {
            printf("\nProduct Found: %s (Current Stock: %d)\n", warehouseStock[i].productName, warehouseStock[i].quantity);
            printf("1. Restock (Add Quantity)\n");
            printf("2. Sell (Deduct Quantity)\n");
            printf("Select operation mode: ");
            scanf("%d", &updateChoice);

            if (updateChoice != 1 && updateChoice != 2) 
            {
                printf("Action Canceled: Operational index unrecognized.\n");
                return;
            }

            printf("Enter quantity volume units: ");
            scanf("%d", &volumeChange);

            if (volumeChange <= 0) 
            {
                printf("Adjustment Aborted: Volume adjustments must be greater than zero.\n");
                return;
            }

            if (updateChoice == 1) 
            {
                warehouseStock[i].quantity += volumeChange;
                printf("Success: Stock inventory refilled. New total: %d units.\n", warehouseStock[i].quantity);
            } 
            else 
            {
                // Safeguard boundary rules to block breaking below zero limits
                if (warehouseStock[i].quantity < volumeChange) 
                {
                    printf("Transaction Denied: Out-of-stock fault. Insufficient inventory quantities.\n");
                    return;
                }
                warehouseStock[i].quantity -= volumeChange;
                printf("Success: Sale logged. Remaining stock level: %d units.\n", warehouseStock[i].quantity);
            }
            return;
        }
    }
    printf("Search Error: Product ID %d was not found inside listings.\n", targetedId);
}
