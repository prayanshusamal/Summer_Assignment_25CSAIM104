#include <stdio.h>
#include <string.h>

int main()      //To check palindrome string
{
    char str[100];
    int length, i, flag = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    length = strlen(str) - 1;

    for (i = 0; i < length; i++, length--)
    {
        if (str[i] != str[length])
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        printf("The string is a palindrome.\n");
    }
    else
    {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}