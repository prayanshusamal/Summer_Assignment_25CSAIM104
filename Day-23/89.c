#include <stdio.h>
#include <string.h>

int main()      //To find first non-repeating character
{
    char str[100];
    int frequency[256] = {0};
    int i, j;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++)
    {
        frequency[str[i]]++;
    }

    for (i = 0; str[i] != '\0'; i++)
    {
        if (frequency[str[i]] == 1)
        {
            printf("First non-repeating character: %c\n", str[i]);
            return 0;
        }
    }

    printf("No non-repeating character found.\n");

    return 0;
}