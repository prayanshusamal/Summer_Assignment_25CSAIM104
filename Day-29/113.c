#include <stdio.h>

// Explicit clean mathematical function prototypes
void renderCalculatorMenu();     //Write a program to Create menu-driven calculator.
void executeAddition();
void executeSubstraction();
void executeMultiplication();
void executeDivision();

int main() 
{
    int executionChoice;

    while (1) 
    {
        renderCalculatorMenu();
        printf("Select execution calculation index: ");
        
        // Defensive input validation check for menu system integers
        if (scanf("%d", &executionChoice) != 1) 
        {
            printf("Error decoding numeric option index. Halting computation interface.\n");
            break;
        }

        switch (executionChoice) 
        {
            case 1:
                executeAddition();
                break;
            case 2:
                executeSubstraction();
                break;
            case 3:
                executeMultiplication();
                break;
            case 4:
                executeDivision();
                break;
            case 5:
                printf("Terminating active processor engine. System offline. Goodbye!\n");
                return 0;
            default:
                printf("Operation index unassigned. Please input an integer from 1 to 5.\n");
        }
    }
    return 0;
}

// Function to print available functional selections clearly
void renderCalculatorMenu() 
{
    printf("\n============== ARITHMETIC CORE CALCULATOR ==============\n");
    printf("1. Core Addition       (+)\n");
    printf("2. Core Subtraction    (-)\n");
    printf("3. Core Multiplication (*)\n");
    printf("4. Core Division       (/)\n");
    printf("5. Shutdown Processing Core\n");
    printf("========================================================\n");
}

// Function performing isolated floating-point addition
void executeAddition() 
{
    double numberA, numberB, outputResult;
    printf("\nEnter first floating-point value: ");
    scanf("%lf", &numberA);
    printf("Enter second floating-point value: ");
    scanf("%lf", &numberB);

    outputResult = numberA + numberB;
    printf("Calculation Finished: %.4f + %.4f = %.4f\n", numberA, numberB, outputResult);
}

// Function performing isolated floating-point subtraction
void executeSubstraction() 
{
    double numberA, numberB, outputResult;
    printf("\nEnter first floating-point value: ");
    scanf("%lf", &numberA);
    printf("Enter second floating-point value: ");
    scanf("%lf", &numberB);

    outputResult = numberA - numberB;
    printf("Calculation Finished: %.4f - %.4f = %.4f\n", numberA, numberB, outputResult);
}

// Function performing isolated floating-point multiplication
void executeMultiplication() 
{
    double numberA, numberB, outputResult;
    printf("\nEnter first floating-point value: ");
    scanf("%lf", &numberA);
    printf("Enter second floating-point value: ");
    scanf("%lf", &numberB);

    outputResult = numberA * numberB;
    printf("Calculation Finished: %.4f * %.4f = %.4f\n", numberA, numberB, outputResult);
}

// Function performing isolated division containing logical crash boundaries
void executeDivision() 
{
    double numberA, numberB, outputResult;
    printf("\nEnter dividend (First value): ");
    scanf("%lf", &numberA);
    printf("Enter divisor (Second value): ");
    scanf("%lf", &numberB);

    // Enforce critical mathematics security boundary check
    if (numberB == 0.0) 
    {
        printf("Critical Mathematics Error: Division by absolute zero is undefined.\n");
        return;
    }

    outputResult = numberA / numberB;
    printf("Calculation Finished: %.4f / %.4f = %.4f\n", numberA, numberB, outputResult);
}
