#include <stdio.h>
#include <string.h>

int main()       //To Check string rotation.
{
    char str1[100], str2[100];
    int len1, len2, i, j, flag = 0;

    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    if (len1 != len2) 
    {
        printf("Strings are not rotations of each other.\n");
        return 0;
    }

    strcat(str1, str1);

    for (i = 0; i < len1; i++) {
        flag = 0;
        for (j = 0; j < len2; j++) 
        {
            if (str1[i + j] != str2[j]) 
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0) 
        {
            printf("Strings are rotations of each other.\n");
            return 0;
        }
    }

    printf("Strings are not rotations of each other.\n");
    return 0;
}