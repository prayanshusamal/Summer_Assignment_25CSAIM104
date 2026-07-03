#include <stdio.h>
#include <string.h>

int main()      //To Sort words by length.                
{
    char words[10][50];
    int i, j, n;

    printf("Enter the number of words: ");
    scanf("%d", &n);

    printf("Enter the words:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%s", words[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strlen(words[i]) > strlen(words[j]))
            {
                char temp[50];
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }

    printf("Words sorted by length:\n");
    
    for (i = 0; i < n; i++)
    {
        printf("%s\n", words[i]);
    }

    return 0;
}