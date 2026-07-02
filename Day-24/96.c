#include <stdio.h>
#include <string.h>

int main()      //To Remove duplicate characters
{
    char str[100], result[100];
    int i, j = 0, len;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);
    for (i = 0; i < len; i++) 
    {
        for (j = 0; j < i; j++) 
        {
            if (str[i] == str[j]) 
            {
                break;
            }
        }
        if (j == i) 
        {
            result[i] = str[i];
        }
    }
    result[i] = '\0';

    printf("String after removing duplicates: %s\n", result);
    return 0;
}