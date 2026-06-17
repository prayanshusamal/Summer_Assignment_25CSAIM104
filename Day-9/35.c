#include <stdio.h>

int main()       //To print repeated character pattern
{
    int i, j, rows;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for(i = 1; i <= rows; i++)
    {
        for(j = 1; j <= i; j++)
        {
            printf("%c ", (i + 64));
        }
        printf("\n");
    }

    return 0;
}