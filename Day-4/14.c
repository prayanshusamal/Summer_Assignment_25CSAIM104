#include<stdio.h>
int main()      //To find nth fibonacci term
{
    int n, a = 0, b = 1, c;
    printf("Enter the term number: ");
    scanf("%d", &n);
    if (n == 0) {
        printf("Fibonacci term at position %d is: %d", n, a);
        return 0;
    } else if (n == 1) {
        printf("Fibonacci term at position %d is: %d", n, b);
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    printf("Fibonacci term at position %d is: %d", n, c);
    return 0;
}