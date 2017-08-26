#include<stdio.h>

int findCrossover(int a[],int x,int low,int high)
{
    if(a[high]<=x)
    return high;
    if(a[low]>x)
    return low;

    int mid=(low+high)/2;
    if(a[mid]<=x && a[mid+1]>x)
    return mid;

    if(a[mid]>x)
    return findCrossover(a,x,low,mid-1);
    else
    return findCrossover(a,x,mid+1,high);
}

void printKClosest(int a[],int x,int k,int n)
{
    int l=findCrossover(a,x,0,n-1);
    int r=l+1;
    printf("%d\n",l);
    if(a[l]==x)
        l--;
    int count=0;
    while(l>=0 && r<n && count<k)
    {
        if(x-a[l]<a[r]-x)
        printf("%d\n",a[l--]);
        else
        printf("%d\n",a[r++]);
        count++;
    }

    while(count<k && l>=0)
        printf("%d\n",a[l--]),count++;
    while(count<k && r<n)
        printf("%d\n",a[r++]),count++;
}

int main()
{
    int arr[]={12, 16, 22, 30, 35, 39, 42,45, 48, 50, 53, 55, 56};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=35,k=4;
    printKClosest(arr,x,k,n);
    return 0;
}
