#include <stdio.h>

int Perfect(int n)    //To write function for perfect number
{
    int i,sum = 0;
    for ( i = 1; i < n; i++) 
    {
        if (n % i == 0) 
        {
            sum += i;
        }
    }
    return sum == n;
}

int main() 
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (Perfect(num)) 
    {
        printf("%d is a perfect number.\n", num);
    } 
    else 
    {
        printf("%d is not a perfect number.\n", num);
    }
    return 0;
}