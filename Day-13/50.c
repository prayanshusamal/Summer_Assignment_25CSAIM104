#include <stdio.h>

int main()    //To find sum and average of array
{
    int arr[10],i, n, sum = 0;
    float avg;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    avg = (float)sum / n;

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", avg);

    return 0;
}