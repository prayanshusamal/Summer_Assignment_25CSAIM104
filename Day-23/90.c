#include <stdio.h>
#include <string.h>

int main()       //To check first repeating character
{
    char str[100];
    int frequency[256] = {0};
    int i;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++)
    {
        frequency[str[i]]++;
        if (frequency[str[i]] == 2)
        {
            printf("First repeating character: %c\n", str[i]);
            return 0;
        }
    }

    printf("No repeating character found.\n");

    return 0;
}