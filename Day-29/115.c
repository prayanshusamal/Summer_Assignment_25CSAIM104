#include <stdio.h>


#define MAX_BUFFER 100     //Write a program to Create menu-driven string operations system.

// Explicit clean functional prototypes
void displayStringMenu();
void computeStringLength();
void executeStringCopy();
void executeStringConcatenation();
void executeStringReverse();

int main() 
{
    int administrativeChoice;

    while (1) 
    {
        displayStringMenu();
        printf("Select active character mutation choice: ");

        // Defensive input verification check for navigation integer parameters
        if (scanf("%d", &administrativeChoice) != 1) 
        {
            printf("Error matching menu integer patterns. Disconnecting text framework.\n");
            break;
        }

        switch (administrativeChoice) 
        {
            case 1:
                computeStringLength();
                break;
            case 2:
                executeStringCopy();
                break;
            case 3:
                executeStringConcatenation();
                break;
            case 4:
                executeStringReverse();
                break;
            case 5:
                printf("Flushing temporary buffer caches. System closing safely!\n");
                return 0;
            default:
                printf("Operation option unrecognized. Re-enter integer ranging 1 to 5.\n");
        }
    }
    return 0;
}

// Function to print available string system operations cleanly
void displayStringMenu() 
{
    printf("\n============== ALPHANUMERIC STRING CORE ==============\n");
    printf("1. Calculate Character Length\n");
    printf("2. Copy String Data to Secondary Buffer\n");
    printf("3. Concatenate Two Separate Strings\n");
    printf("4. Reverse String Character Sequence\n");
    printf("5. Exit Text Workspace Framework\n");
    printf("======================================================\n");
}

// Function calculating length manually using null-terminator flags
void computeStringLength() 
{
    char rawString[MAX_BUFFER];
    int trackingLength = 0;

    printf("\nEnter a string sequence: ");
    getchar(); // Purge residual line feeds from incoming pipelines
    
    // Read input string character by character until a newline is hit
    char ch;
    while (trackingLength < MAX_BUFFER - 1 && (ch = getchar()) != '\n' && ch != EOF) 
    {
        rawString[trackingLength++] = ch;
    }
    rawString[trackingLength] = '\0'; // Set clean string termination flag

    printf("Analysis Finished: Character length calculation totals %d units.\n", trackingLength);
}

// Function handling character copying workflows between buffer states
void executeStringCopy() 
{
    char sourceBuffer[MAX_BUFFER];
    char destinationBuffer[MAX_BUFFER];
    int charIndex = 0;

    printf("\nEnter source string data to copy: ");
    getchar(); // Clear stream path
    
    char ch;
    while (charIndex < MAX_BUFFER - 1 && (ch = getchar()) != '\n' && ch != EOF) 
    {
        sourceBuffer[charIndex++] = ch;
    }
    sourceBuffer[charIndex] = '\0';

    // Transfer loop tracing index addresses manually
    int copyIndex = 0;
    while (sourceBuffer[copyIndex] != '\0')
    {
        destinationBuffer[copyIndex] = sourceBuffer[copyIndex];
        copyIndex++;
    }
    destinationBuffer[copyIndex] = '\0'; // Seal output memory block securely

    printf("Processing Event: Duplication confirmed.\n");
    printf("Source Data     : [%s]\n", sourceBuffer);
    printf("Destination Copy: [%s]\n", destinationBuffer);
}

// Function joining two independent character matrices safely inside memory limits
void executeStringConcatenation() 
{
    char firstString[MAX_BUFFER];
    char secondString[MAX_BUFFER];
    char outputCombined[MAX_BUFFER * 2];
    int lengthA = 0, lengthB = 0;

    printf("\nEnter the initial string base: ");
    getchar(); // Clear stray stream frames
    char ch;
    while (lengthA < MAX_BUFFER - 1 && (ch = getchar()) != '\n' && ch != EOF) 
    {
        firstString[lengthA++] = ch;
    }
    firstString[lengthA] = '\0';

    printf("Enter the string to append: ");
    while (lengthB < MAX_BUFFER - 1 && (ch = getchar()) != '\n' && ch != EOF) 
    {
        secondString[lengthB++] = ch;
    }
    secondString[lengthB] = '\0';

    // Phase 1: Transfer first block to target layout
    int combinedTracker = 0;
    for (int i = 0; i < lengthA; i++) 
    {
        outputCombined[combinedTracker++] = firstString[i];
    }

    // Phase 2: Append secondary block right after index baseline shifts
    for (int i = 0; i < lengthB; i++) 
    {
        outputCombined[combinedTracker++] = secondString[i];
    }
    outputCombined[combinedTracker] = '\0'; // Safety seal array endpoints

    printf("Processing Event: Concatenation operations complete.\n");
    printf("Resulting String Profile: [%s]\n", outputCombined);
}

// Function processing positional swapping vectors to reverse strings
void executeStringReverse() 
{
    char basicString[MAX_BUFFER];
    char flippedString[MAX_BUFFER];
    int inputLength = 0;

    printf("\nEnter target text to reverse: ");
    getchar(); // Purge buffer frames
    char ch;
    while (inputLength < MAX_BUFFER - 1 && (ch = getchar()) != '\n' && ch != EOF) 
    {
        basicString[inputLength++] = ch;
    }
    basicString[inputLength] = '\0';

    // Read source characters from right to left, and write to destination from left to right
    int writeIndex = 0;
    for (int readIndex = inputLength - 1; readIndex >= 0; readIndex--) 
    {
        flippedString[writeIndex++] = basicString[readIndex];
    }
    flippedString[writeIndex] = '\0';

    printf("Processing Event: Character line layout inverted.\n");
    printf("Original Orientation: [%s]\n", basicString);
    printf("Reversed Orientation: [%s]\n", flippedString);
}
