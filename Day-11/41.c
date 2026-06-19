#include <stdio.h>

int sum(int a, int b)   // To Write function to find sum of two numbers.
{
    return a + b;
}

int main()
{
    int x, y;
    printf("Enter value of x:");
    scanf("%d",&x);
    printf("Enter value of y:");
    scanf("%d",&y);
    printf("Sum of two numbers is %d\n", sum(x, y));
    return 0;
}