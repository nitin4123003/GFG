#include<stdio.h>
int main()
{
    int num=6;
    int val=fib(num);
    printf("Value=%d",val);
    return 0;
}

int fib(int num)
{
    if(num==1)
    return 1;
    if(num==0)
    return 1;

    return (fib(num-1)+fib(num-2));
}
