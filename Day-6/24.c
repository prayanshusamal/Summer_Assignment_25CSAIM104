#include <stdio.h>
int main()      //To Find x^n without pow().
{
    double x, result = 1.0;
    int n, i;
    printf("Enter a base number (x): ");
    scanf("%lf", &x);
    printf("Enter an exponent (n): ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        result *= x;
    }
    printf("%.2lf raised to the power of %d is: %.2lf", x, n, result);
    return 0;
}