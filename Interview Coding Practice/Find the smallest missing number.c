#include<stdio.h>

int findMissing(int arr[],int low,int high)
{
    if(low>high)
    return high+1;

    if(low!=arr[low])
    return low;

    int mid=low+(high-low)/2;

    if(arr[mid]>mid)
    return findMissing(arr,low,mid);
    else
    return findMissing(arr,mid+1,high);
}

int main()
{
    int arr[]={0, 1, 4, 5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("The element missing is %d\n",findMissing(arr,0,n-1));
}
