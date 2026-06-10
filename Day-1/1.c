#include<stdio.h>
int main()
{
    int N,i,sum=0;
    printf("Enter a Number:");
    scanf("%d",&N);

    for(i=1;i<=N;i++)
    {
        sum=sum+i;
    }
    printf("The Sum is %d",sum);
    return 0;
    
}