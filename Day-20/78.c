#include <stdio.h>

int main()      //To check symmetric matrix
{
    int a[10][10], m, n, i, j, symmetric = 1;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d%d", &m, &n);

    if (m != n) 
    {
        printf("Matrix is not square, hence cannot be symmetric.\n");
        return 0;
    }

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < m; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < m; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            if (a[i][j] != a[j][i]) 
            {
                symmetric = 0;
                break;
            }
        }
        if (!symmetric) 
        {
            break;
        }
    }

    if (symmetric) 
    {
        printf("The matrix is symmetric.\n");
    } 
    else 
    {
        printf("The matrix is not symmetric.\n");
    }

    return 0;
}