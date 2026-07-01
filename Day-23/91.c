#include <stdio.h>
#include <string.h>

int main()     //To check anagram strings
{
    char str1[100], str2[100];
    int frequency[256] = {0};
    int i, len1, len2;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter second string: ");
    fgets(str2, sizeaof(str2), stdin);

    len1 = strlen(str1);
    len2 = strlen(str2);

    if (len1 != len2)
    {
        printf("Strings are not anagrams.\n");
        return 0;
    }

    for (i = 0; i < len1; i++)
    {
        frequency[str1[i]]++;
        frequency[str2[i]]--;
    }

    for (i = 0; i < 256; i++)
    {
        if (frequency[i] != 0)
        {
            printf("Strings are not anagrams.\n");
            return 0;
        }
    }

    printf("Strings are anagrams.\n");

    return 0;
}