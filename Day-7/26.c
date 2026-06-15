#include <stdio.h>

int fib(int n)    //To Recursive Fibonacci
{
    
if (n == 0) 
{
    return 0;
} 
else if (n == 1) 
{
    return 1;
}
    
else 
{
    return fib(n - 1) + fib(n - 2);
}
}

int main() 
{
    
int t;

printf("Enter the number of terms: ");
scanf("%d", &t);

if (t <= 0) 
{
     printf("Enter a positive integer.\n");
}
 else 
 {
    printf("Fibonacci Series: ");
       
    for (int i = 0; i < t; i++) 
    {
        printf("%d ", fib(i));
    }
    printf("\n");
}

    return 0;
}