#include <stdio.h>
#include <string.h>

int main()      //To Find longest word
{
    char str[100], longest[100];
    int i, j = 0, max = 0, len;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);
    for (i = 0; i < len; i++) 
    {
        if (str[i] == ' ') 
        {
            if (j > max) 
            {
                max = j;
                strncpy(longest, str + i - j, max);
                longest[max] = '\0';
            }
            j = 0;
        } 
        else 
        {
            j++;
        }
    }
    if (j > max) 
    {
        max = j;
        strncpy(longest, str + len - j, max);
        longest[max] = '\0';
    }

    printf("Longest word: %s\n", longest);
    return 0;
}