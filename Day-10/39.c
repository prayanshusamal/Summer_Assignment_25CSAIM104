#include <stdio.h>

int main()     //To print number pyramid
{
    int i,j,rows;
    printf("Enter the number of rows:");
    scanf("%d",&rows);

    for (int i = 1; i <= rows; i++)
    {
        
        for (int j = 1; j <= rows - i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("%d", j);
        }
        for (int j = i - 1; j >= 1; j--)
        {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}
