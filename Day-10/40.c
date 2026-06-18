#include <stdio.h>

int main()      //To print character pyramid
{
    int i,j,rows;
    printf("Enter number of rows:");
    scanf("%d",&rows);

    for (int i = 1; i <= rows; i++)
    {
        for (int space = 1; space <= rows - i; space++) 
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("%c", 'A' + j - 1);
        }
        for (int j = i - 1; j >= 1; j--)
        {
            printf("%c", 'A' + j - 1);
        }
        printf("\n");
    }

    return 0;
}