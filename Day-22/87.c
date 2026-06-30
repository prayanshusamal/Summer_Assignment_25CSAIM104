#include <stdio.h>

int main()     //To count frequency of each character
{
    char str[100];
    int frequency[256] = {0};  
    int i;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++)
    {
        frequency[str[i]]++;
    }

    printf("Character frequencies:\n");
    for (i = 0; i < 256; i++)
    {
        if (frequency[i] > 0)
        {
            printf("'%c': %d\n", i, frequency[i]);
        }
    }

    return 0;
}