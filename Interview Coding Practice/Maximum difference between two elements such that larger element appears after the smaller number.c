#include<stdio.h>

int findMaxDiff(int array[],int n)
{
    int i,max_diff=-1,max_so_far;
    max_so_far=array[n-1];
    for(i=n-2;i>=0;i--)
    {
        if(array[i]>max_so_far)
        max_so_far=array[i];
        if(array[i]<max_so_far && max_diff<(max_so_far-array[i]))
        max_diff=max_so_far-array[i];
    }
    return max_diff;
}

int main()
{
    int array[]={7, 9, 5, 6, 3, 2};
    int n=sizeof(array)/sizeof(array[0]);
    int max_diff=findMaxDiff(array,n);
    printf("%d",max_diff);
}
