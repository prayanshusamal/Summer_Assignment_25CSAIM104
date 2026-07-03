#include <stdio.h>
#include <string.h>

int main()      //To Find common characters in strings.
{
    char str1[100], str2[100], common[100];
    int i, j, k = 0, len1, len2;

    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    for (i = 0; i < len1; i++) 
    {
        for (j = 0; j < len2; j++) 
        {
            if (str1[i] == str2[j]) 
            {
                common[k] = str1[i];
                k++;
                break;
            }
        }
    }
    common[k] = '\0';

    printf("Common characters: %s\n", common);
    return 0;
}