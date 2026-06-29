#include <stdio.h>
#include <ctype.h>

int main()      //To convert lowercase to uppercase
{
    char str[100];
    int i;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (islower(str[i]))
        {
            str[i] = toupper(str[i]);
        }
    }

    printf("String in uppercase: %s", str);

    return 0;
}