#include <stdio.h>
int main()    //To find missing elements in an array
{
    int n, i, j, arr[10];
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The missing elements are: ");
    for (i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] - arr[i] > 1)
        {
            for (j = arr[i] + 1; j < arr[i + 1]; j++)
            {
                printf("%d ", j);
            }
        }
    }
    return 0;
}