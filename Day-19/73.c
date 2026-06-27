#include <stdio.h>

int main()     //To add matrices
{
    int a[10][10], b[10][10], c[10][10], m, n, i, j;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);
    printf("Enter the elements of the first matrix: ");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the elements of the second matrix: ");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("The sum of the matrices is: ");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}