#include <stdio.h>
#include <math.h>

int rev(int n)    //To Recursive reverse number
{
if (n == 0) 
{
    return 0;
}
else 
{
    return (n % 10) * (int)(pow(10, (int)log10(n))) + rev(n / 10);
}
}

int main() 
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Reversed number: %d\n", rev(num));
    return 0;
}