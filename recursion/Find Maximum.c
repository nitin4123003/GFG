#include<stdio.h>

int findMax(int arr[],int low,int high)
{
    if(low==high)
    return arr[low];
    else
    {
        int max1=findMax(arr,low+1,high);
        if(max1>arr[low])
        return max1;
        else
        return arr[low];
    }
}

int main()
{
    int arr[]={4,1,9,3,7};
    int n=5;
    int max=findMax(arr,0,n-1);
    printf("%d",max);
}
