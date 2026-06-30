#include <stdio.h>

int main()     //To count words in a sentence
{
    char str[100];
    int words = 1;  
    int i;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            words++;
        }
    }

    printf("Number of words: %d\n", words);

    return 0;
}