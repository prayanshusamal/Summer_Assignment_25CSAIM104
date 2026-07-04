#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()    //To Create number guessing game.
{
    int n, guess, attempts = 0;
    srand(time(0));
    n = rand() % 100 + 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between 1 and 100.\n");
    printf("Try to guess it!\n");

    while (1)
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess == n)
        {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            break;
        }
        else if (guess < n)
        {
            printf("Too low! Try again.\n");
        }
        else
        {
            printf("Too high! Try again.\n");
        }
    }

    return 0;
}