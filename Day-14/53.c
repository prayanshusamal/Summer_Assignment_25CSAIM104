#include <stdio.h>
int main()     //To linear search
{
    int arr[10], i, n, x, flag = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &x);

    for (i = 0; i < n; i++) 
    {
        if (arr[i] == x) 
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1) 
    {
        printf("Element found at %dth position\n", i+1);
    } 
    else 
    {
        printf("Unsuccessful search\n");
    }

    return 0;
}