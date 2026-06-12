#include <stdio.h>
int main()       //To Print Armstrong numbers in a range
{
    int n1, n2, i, temp, d, s;
    printf("Enter the lower and upper limits: ");
    scanf("%d %d", &n1, &n2);
    printf("Armstrong numbers between %d and %d are: ", n1, n2);
    for (i = n1; i <= n2; i++)
    {
        temp = i;
        s = 0;
        while (temp != 0)
        {
            d = temp % 10;
            s += d * d * d;
            temp /= 10;
        }
        if (s == i)
            printf("%d ", i);
    }
    return 0;
}