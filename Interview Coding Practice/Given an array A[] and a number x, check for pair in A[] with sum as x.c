#include<stdio.h>

int findMin(int arr[],int n)
{
    int i,min_val=8000;
    for(i=0;i<n;i++)
    {
        if(arr[i]<min_val)
        min_val=arr[i];
    }
    return min_val;
}

void printPair(int arr[],int n,int x)
{

    int min=abs(findMin(arr,n));
    //printf("%d",min);
    x=x+2*min;
    int hashMap[10000]={0},i;
    for(i=0;i<n;i++)
    arr[i]+=min;
    for(i=0;i<n;i++)
    {
        if(hashMap[x-arr[i]]==1)
        printf("Pair is %d and %d\n",arr[i]-min,x-arr[i]-min);
        else
        hashMap[arr[i]]=1;
    }
}

int main()
{
    int arr[]={1,4,45,6,10,8};
    int x=16;
    int n=sizeof(arr)/sizeof(int);
    printPair(arr,n,x);
}
