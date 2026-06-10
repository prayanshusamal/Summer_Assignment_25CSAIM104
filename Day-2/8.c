#include<stdio.h>
int main()     // This program checks whether a given number is a palindrome or not.
{
    int n,d,rev=0,temp;
    printf("Enter a number: "); 
    scanf("%d",&n);
    temp=n;
    while(n>0)
    {
        d=n%10;
        rev=rev*10+d;
        n=n/10;
    }
    if(temp==rev)
        printf("The number is a palindrome.\n");
    else
        printf("The number is not a palindrome.\n");
    return 0;
}
