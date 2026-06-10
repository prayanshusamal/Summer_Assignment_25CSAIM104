#include <stdio.h>
int main()   // This program calculates the sum of the digits of a given number.
{
    int  n,d,s=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    while(n>0)
    {
        d=n%10;
        s=s+d;
        n=n/10;
    }
    printf("Sum of digits: %d\n", s);
    return 0;
}