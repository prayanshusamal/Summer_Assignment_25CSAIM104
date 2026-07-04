#include <stdio.h>
#include <string.h>

int main()    //To Create quiz application.
{
    char question1[] = "What is the capital of France?";
    char question2[] = "What is 2 + 2?";
    char question3[] = "What is the largest planet in our solar system?";

    char answer1[] = "Paris";
    char answer2[] = "4";
    char answer3[] = "Jupiter";

    char userAnswer[100];
    int score = 0;

    printf("Welcome to the Quiz!\n");

    printf("%s\n", question1);
    scanf("%s", userAnswer);
    if (strcmp(userAnswer, answer1) == 0)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Incorrect.\n");
    }

    printf("%s\n", question2);
    scanf("%s", userAnswer);
    if (strcmp(userAnswer, answer2) == 0)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Incorrect.\n");
    }

    printf("%s\n", question3);
    scanf("%s", userAnswer);
    if (strcmp(userAnswer, answer3) == 0)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Incorrect.\n");
    }

    printf("Your final score is: %d out of 3\n", score);
    return 0;
}