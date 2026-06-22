#include <stdio.h>
int main()    //To find duplicate elements in an array
{
    int n, i, j, count = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Duplicate elements in the array are: ");
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                printf("%d ", arr[i]);
                count++;
                break;
            }
        }
    }
    if (count == 0)
    {
        printf("No duplicate elements found .\n");
    }
    return 0;
}