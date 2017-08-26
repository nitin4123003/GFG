#include<stdio.h>

int pivotedBinSearch(int arr[],int low,int high,int x,int pivot)
{
    if(arr[0]<=x)
    high=pivot-1;
    else
    low=pivot+1;

    //Binary Search
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==x) return mid;
        else if(arr[mid]<x)
            low=mid+1;
        else if(arr[mid]>x)
            high=mid-1;
    }
}

int findPivot(int arr[],int low,int high)
{
    if(high<low)
    return -1;
    if(high==low)
    return low;
    int mid=low+high/2;
    if(arr[mid]>arr[mid+1])
    return mid;
    if(arr[mid-1]>arr[mid])
    return mid-1;
    if(arr[low]>arr[mid])
    return findPivot(arr,low,mid-1);
    else
    return findPivot(arr,mid+1,high);
}

int main()
{
    int array[]={3,4,5,6,1,2};
    int n=sizeof(array)/sizeof(int);
    int pivot=findPivot(array,0,n);
    printf("%d\n\n",array[pivot]);
    int x=5;
    if(array[pivot]==x)
    printf("%d",pivot+1);
    else//printf("%d",array[pivot]);
    {
        int index=pivotedBinSearch(array,0,n,x,pivot);
        printf("%d",index+1);
    }
}
