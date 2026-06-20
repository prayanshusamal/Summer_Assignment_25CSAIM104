#include <stdio.h>
#include <math.h>

int Armstrong(int n)   //To write function for Armstrong number
{
    int original = n, sum = 0, d;
    while (n > 0)
    {
        d = n % 10;
        sum += pow(d, 3);
        n /= 10;
    }
    return original == sum;
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (Armstrong(num))
    {
        printf("%d is an Armstrong number.\n", num);
    }
    else
    {
        printf("%d is not an Armstrong number.\n", num);
    }
    return 0;
}