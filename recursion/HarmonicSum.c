#include<stdio.h>

float harmonicSum(int n)
{
    if(n==1)
    return 1.00;
    else
    {
        float res=1/(float)n;
        printf("%.4f\n",res);
        return (harmonicSum(n-1)+res);
    }
}

int main()
{
    int n=5;
    printf("%.4f",harmonicSum(n));
    return 0;
}
