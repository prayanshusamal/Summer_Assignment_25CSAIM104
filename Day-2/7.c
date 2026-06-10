#include<stdio.h>
int main()  // This program calculates the product of the digits of a given number.
{
    int n,d,p=1;
    printf("Enter a number: ");
    scanf("%d",&n);
    while(n>0)
    {
        d=n%10;
        p=p*d;
        n=n/10;
    }
    printf("Product of the digits is: %d\n", p);
    return 0;
}