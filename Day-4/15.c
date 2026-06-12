#include <stdio.h>  //To check whether the given number is armstrong 
int main()
{
    int n, temp, d, s= 0;
    printf("Enter an integer: ");
    scanf("%d", &n);
    temp = n;
    while (temp != 0)
    {
        d = temp % 10;
        s += d * d * d;
        temp /= 10;
    }
    if (s == n)
        printf("%d is an Armstrong number.", n);
    else
        printf("%d is not an Armstrong number.", n);
    return 0;
}