#include <stdio.h>
#include <string.h>

int main()      //To reverse a string
{
    char str[100];
    int length, i, j;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    length = strlen(str) - 1;

    printf("Reversed string: ");
    for (i = length, j = 0; i >= 0; i--, j++)
    {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}