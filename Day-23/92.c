#include <stdio.h>
#include <string.h>

int main()       //To find maximum occurring character
{
    char str[100];
    int frequency[256] = {0};
    int i, max_freq = 0, max_char;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++)
    {
        frequency[str[i]]++;
    }

    for (i = 0; i < 256; i++)
    {
        if (frequency[i] > max_freq)
        {
            max_freq = frequency[i];
            max_char = i;
        }
    }

    printf("Maximum occurring character: %c\n", max_char);
    printf("Frequency: %d\n", max_freq);

    return 0;
}