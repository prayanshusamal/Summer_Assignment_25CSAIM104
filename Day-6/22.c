#include <stdio.h>
int main()        //To convert binary to decimal
{
    int binary, decimal = 0, i = 1;
    printf("Enter a binary number: ");
    scanf("%d", &binary);
    while (binary != 0)
    {
        decimal += (binary % 10) * i;
        binary /= 10;
        i *= 2;
    }
    printf("Decimal equivalent: %d", decimal);
    return 0;
}