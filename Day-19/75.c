#include <stdio.h>

int main()   //To tranpose a matrix
{
    int a[10][10], b[10][10], m, n, i, j;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);
    printf("Enter the elements of the matrix: ");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            b[j][i] = a[i][j];
        }
    }
    printf("The transpose of the matrix is: ");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}