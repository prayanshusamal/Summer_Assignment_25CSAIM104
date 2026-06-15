#include <stdio.h>

int SOD(int n)   //To Recursive sum of digits
{
if (n == 0) 
{
    return 0;
} 
else 
{
        
    return (n % 10) + SOD(n / 10);
}
}

int main() 
{
    
int num;
printf("Enter a number: ");
scanf("%d", &num);
if (num < 0) 
{
    printf("Enter a positive integer.\n");
} 
else 
{
    printf("Sum of digits: %d\n", SOD(num));
}
    return 0;
}