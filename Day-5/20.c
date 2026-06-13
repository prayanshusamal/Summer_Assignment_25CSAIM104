#include <stdio.h>
int main()       //To find largest prime factor 
{
    int n, i, max_prime = -1;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    while (n % 2 == 0)
    {
        max_prime = 2;
        n /= 2;
    }
    for (i = 3; i <= n; i += 2)
    {
        while (n % i == 0)
        {
            max_prime = i;
            n /= i;
        }
    }
    if (n > 2)
        max_prime = n;
    if (max_prime != -1)
        printf("The largest prime factor is: %d", max_prime);
    else
        printf("No prime factors found.");
    return 0;
}