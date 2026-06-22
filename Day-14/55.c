#include <stdio.h>
int main()     //To second largest element in an array
{
    int arr[10], i, n, largest, second_largest;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    largest = second_largest = arr[0];

    for (i = 1; i < n; i++) 
    {
        if (arr[i] > largest) 
        {
            second_largest = largest;
            largest = arr[i];
        } 
        else if (arr[i] > second_largest && arr[i] != largest) 
        {
            second_largest = arr[i];
        }
    }

    if (second_largest == largest) 
    {
        printf("There is no second largest element.\n");
    } 
    else 
    {
        printf("The second largest element is: %d\n", second_largest);
    }

    return 0;
}