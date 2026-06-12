#include<stdio.h>
int main() //To generate fibonacci series
{
    int n, a = 0, b = 1, c;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++)
 {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    return 0;
}