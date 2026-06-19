#include <stdio.h>  

int Max(int a, int b)     //To write a function to find the maximum of two numbers
{
    return (a > b) ? a : b;
}

int main() 
{
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    printf("The maximum value is %d\n",  Max(x, y));
    return 0;
}