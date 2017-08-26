#include<stdio.h>

int max(int a,int b)
{
    return (a>b?a:b);
}

int knapsack(int val[],int wt[],int n,int W)
{
    if(n==0 || W <=0)
    return 0;

    if(wt[n-1]>W)
    return knapsack(val,wt,n-1,W);
    else
    return max( (knapsack(val,wt,n-1,W-wt[n-1])+val[n-1]),knapsack(val,wt,n-1,W) );

}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d", knapsack(val,wt,n,W));
    return 0;
}
