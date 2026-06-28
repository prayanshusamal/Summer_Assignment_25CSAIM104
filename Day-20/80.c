#include <stdio.h>

int main()      //To  column wise sum of a matrix
{
    int a[10][10], m, n, i, j, sum;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d%d", &m, &n);

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < m; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Column wise sum of the matrix:\n");
    for (j = 0; j < n; j++) 
    {
        sum = 0;
        for (i = 0; i < m; i++) 
        {
            sum += a[i][j];
        }
        printf("Sum of column %d: %d\n", j + 1, sum);
    }

    return 0;
}