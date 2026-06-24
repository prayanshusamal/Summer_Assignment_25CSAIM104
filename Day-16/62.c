#include <stdio.h>
int main()     //To find maximum frequency element in an array
{
    int n, i, j, count, maxCount = 0, maxElement;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        count = 1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            maxElement = arr[i];
        }
    }
    printf("The maximum frequency element is: %d\n", maxElement);
    return 0;
}