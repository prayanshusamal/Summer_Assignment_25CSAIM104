#include<stdio.h>
int main()       // This program calculates the reverse of a given number.
{
    int n,d,rev=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    while(n>0)
    {
        d=n%10;
        rev=rev*10+d;
        n=n/10;
    }
    printf("Reverse of the number is: %d\n", rev);
    return 0;
}