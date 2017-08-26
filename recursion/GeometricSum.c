#include<stdio.h>

float geometricSum(int n)
{
    if(n==0)
    return 1.0;
    else
    {
        float res=1/(float)(1<<n);
        printf("%.4f\n",res);
        return (geometricSum(n-1)+res);
    }
}

int main()
{
    int n=2;
    printf("%.4f",geometricSum(n));
    return 0;
}
