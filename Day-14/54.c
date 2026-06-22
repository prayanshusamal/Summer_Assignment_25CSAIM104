#include <stdio.h>
int main()      //To find frequency of an elements
{
    int arr[10], i, j, n, count = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
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
        if (count > 1) 
        {
            printf("Element %d occurs %d times\n", arr[i], count);
        }
    }

    return 0;
}