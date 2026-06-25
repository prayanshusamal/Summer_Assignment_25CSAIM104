#include <stdio.h>
int main()       //To union of arrays
{
    int n1, n2, i, j, k = 0;
    printf("Enter the size of the first array: ");
    scanf("%d", &n1);
    printf("Enter the size of the second array: ");
    scanf("%d", &n2);
    int arr1[n1], arr2[n2], unionArr[n1 + n2];
    printf("Enter the elements of the first array: ");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
        unionArr[k++] = arr1[i];
    }
    printf("Enter the elements of the second array: ");
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
        int found = 0;
        for (j = 0; j < n1; j++)
        {
            if (arr2[i] == arr1[j])
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            unionArr[k++] = arr2[i];
        }
    }
    printf("The union of the arrays is: ");
    for (i = 0; i < k; i++)
    {
        printf("%d ", unionArr[i]);
    }
    return 0;
}