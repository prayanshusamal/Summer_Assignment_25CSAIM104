#include <stdio.h>

int main()        // To Count set bits in a number.
{
    int n, count = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    while (n != 0)
    {
        count += n & 1;
        n >>= 1;
    }
    printf("Number of set bits: %d", count);
    return 0;
}