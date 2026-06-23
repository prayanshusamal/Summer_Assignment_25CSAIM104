#include <stdio.h>
int main()      //To moves zeroes to the end of an array
{
    int n, i, j, temp, arr[10];
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (j = i; j < n - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            arr[n - 1] = 0;
        }
    }
    printf("The array with zeroes at the end is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}