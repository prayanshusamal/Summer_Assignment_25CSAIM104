#include <stdio.h>
int factorial(int n)       //To check strong number
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}
int main()
{
    int n, temp, d, s = 0;
    printf("Enter an integer: ");
    scanf("%d", &n);
    temp = n;
    while (temp != 0)
    {
        d = temp % 10;
        s += factorial(d);
        temp /= 10;
    }
    if (s == n)
        printf("%d is a strong number.", n);
    else
        printf("%d is not a strong number.", n);
    return 0;
}
