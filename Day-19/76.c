#include <stdio.h>

int main()   //To find diagonal sum of a matrix
{
    int a[10][10], m, n, i, j, sum = 0;
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
            if(i == j)
            {
                sum += a[i][j];
            }
        }
    }
    printf("The diagonal sum of the matrix is: %d", sum);
    return 0;
}