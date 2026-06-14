#include <stdio.h>
int main()        //To convert decimal to binary
{
    int decimal, binary = 0, i = 1;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    while (decimal != 0)
    {
        binary += (decimal % 2) * i;
        decimal /= 2;
        i *= 10;
    }
    printf("Binary equivalent: %d", binary);
    return 0;
}