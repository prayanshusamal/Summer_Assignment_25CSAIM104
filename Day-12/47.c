#include <stdio.h>

int fib(int n)    //To write function for fibonacci series
{
    if (n <= 0) 
    return 0;
    if (n == 1) 
    return 1;
    else
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int terms;
    
    printf("Enter the number of terms: ");
    scanf("%d", &terms);
    
    printf("Fibonacci Series : ");
    for (int i = 0; i < terms; i++) 
    {
        printf("%d ", fib(i));
    }
    printf("\n");
    return 0;
}