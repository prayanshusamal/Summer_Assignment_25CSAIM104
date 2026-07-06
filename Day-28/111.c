#include <stdio.h>
#include <string.h>

#define TOTAL_ROWS 5      //Write a program to Create ticket booking system.
#define SEATS_PER_ROW 6
#define NAME_LENGTH 50

// Structure representing an individual ticket reservation seat
typedef struct 
{
    int seatNumber;
    int isBooked; // 0 = Available, 1 = Reserved/Booked
    char passengerName[NAME_LENGTH];
} 
Seat;

// 2D Array matrix layout representing a venue grid layout
Seat venueLayout[TOTAL_ROWS][SEATS_PER_ROW];

// Explicit clean function prototypes
void initializeVenueMap();
void displaySeatingChart();
void reserveTicket();
void cancelTicket();
void displayTerminalMenu();

int main() 
{
    int menuOption;

    // Run dynamic structure grid allocation state setup once at starting frame
    initializeVenueMap();

    while (1) 
    {
        displayTerminalMenu();
        printf("Enter operational choice index: ");
        
        // Defensive input matching validations
        if (scanf("%d", &menuOption) != 1) 
        {
            printf("Error decoding numeric formats. Shutting down system interface.\n");
            break;
        }

        switch (menuOption) 
        {
            case 1:
                displaySeatingChart();
                break;
            case 2:
                reserveTicket();
                break;
            case 3:
                cancelTicket();
                break;
            case 4:
                printf("Closing Terminal Matrix Connection. System safe. Goodbye!\n");
                return 0;
            default:
                printf("Operation code unassigned. Input an integer between 1 and 4.\n");
        }
    }
    return 0;
}

// Function to cleanly render user operational choices
void displayTerminalMenu() 
{
    printf("\n============== TICKET RESERVATION TERMINAL ==============\n");
    printf("1. View Live Matrix Seating Chart\n");
    printf("2. Purchase & Reserve explicit Seat Ticket\n");
    printf("3. Cancel Registered Seat Ticket Reservation\n");
    printf("4. Disconnect Application Terminal\n");
    printf("=========================================================\n");
}

// Function running nested loops to auto-calculate linear seat IDs across arrays
void initializeVenueMap() 
{
    int trackingCounter = 1;
    for (int r = 0; r < TOTAL_ROWS; r++) 
    {
        for (int s = 0; s < SEATS_PER_ROW; s++) 
        {
            venueLayout[r][s].seatNumber = trackingCounter++;
            venueLayout[r][s].isBooked = 0;
            strcpy(venueLayout[r][s].passengerName, "");
        }
    }
}

// Function to print graphical text matrix representation of current booking layout
void displaySeatingChart() 
{
    printf("\n================ STAGE / SCREEN DIRECTION ================\n\n");
    for (int r = 0; r < TOTAL_ROWS; r++) 
    {
        printf("Row %02d:  ", r + 1);
        for (int s = 0; s < SEATS_PER_ROW; s++) 
        {
            if (venueLayout[r][s].isBooked == 0) 
            {
                // If index is empty print standard seat numerical layout reference tag
                printf("[%02d:Available] ", venueLayout[r][s].seatNumber);
            } 
            else 
            {
                // Highlight booked fields visually using uniform bounding brackets
                printf("[  X:Booked ] ");
            }
        }
        printf("\n");
    }
    printf("\n==========================================================\n");
}

// Function managing target address mapping values to commit secure reservations
void reserveTicket() 
{
    int requestedSeatId;
    int indexFoundFlag = 0;

    printf("Input preferred Seat ID Number to book: ");
    scanf("%d", &requestedSeatId);

    // Scan complete 2D matrix structure safely for tracking target coordinates
    for (int r = 0; r < TOTAL_ROWS; r++) 
    {
        for (int s = 0; s < SEATS_PER_ROW; s++) 
        {
            if (venueLayout[r][s].seatNumber == requestedSeatId) 
            {
                indexFoundFlag = 1;

                // Stop duplicate overriding collisions cleanly
                if (venueLayout[r][s].isBooked == 1) 
                {
                    printf("Booking Error: Seat ID %d is already taken by another profile.\n", requestedSeatId);
                    return;
                }

                printf("Enter Primary Passenger Full Name: ");
                getchar(); // Purge residual pipe line breaking carriage markers out
                fgets(venueLayout[r][s].passengerName, NAME_LENGTH, stdin);
                venueLayout[r][s].passengerName[strcspn(venueLayout[r][s].passengerName, "\n")] = 0; // Strip lines

                venueLayout[r][s].isBooked = 1;
                printf("Success: Ticket processing complete! Seat %d is reserved.\n", requestedSeatId);
                return;
            }
        }
    }

    if (indexFoundFlag == 0) 
    {
        printf("Registry Fault: Seat code %d does not exist inside layout metrics.\n", requestedSeatId);
    }
}

// Function parsing state indices to unlock booked components safely
void cancelTicket() 
{
    int releaseSeatId;
    int indexFoundFlag = 0;

    printf("Input registered Seat ID Number to cancel: ");
    scanf("%d", &releaseSeatId);

    for (int r = 0; r < TOTAL_ROWS; r++) 
    {
        for (int s = 0; s < SEATS_PER_ROW; s++) 
        {
            if (venueLayout[r][s].seatNumber == releaseSeatId) 
            {
                indexFoundFlag = 1;

                if (venueLayout[r][s].isBooked == 0) 
                {
                    printf("Cancellation Notice: Seat ID %d is already open and unreserved.\n", releaseSeatId);
                    return;
                }

                // Reset parameters back to default state baseline boundaries
                venueLayout[r][s].isBooked = 0;
                printf("Success: Ticket issued to %s was removed. Seat %d is now available.\n", 
                       venueLayout[r][s].passengerName, releaseSeatId);
                strcpy(venueLayout[r][s].passengerName, "");
                return;
            }
        }
    }

    if (indexFoundFlag == 0) 
    {
        printf("Registry Fault: Seat code %d not found inside registry layout bounds.\n", releaseSeatId);
    }
}
