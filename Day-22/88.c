#include <stdio.h>
#include <string.h>

int main()       //To remove spaces from a string
{
    char str[100];
    int i, j;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0, j = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';

    printf("String after removing spaces: %s\n", str);

    return 0;
}