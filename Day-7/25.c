#include <stdio.h>

long long factorial(int n)   //To Recursive  factorial 
{
    if (n == 0|| n==1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() 
{
   int num;
    printf("Enter a number: ");
    scanf("%ld", &num);
    printf("Factorial of %d is %lld\n", num, factorial(num));
    return 0;
}