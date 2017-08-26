#include<stdio.h>
#include<conio.h>
int main()
{
    int a[]={1,2,3,4};
    int n=sizeof(a)/sizeof(a[0]);
    int minn=min(a,n,0,n-1);
    printf("%d",minn);
    getch();
}

int min(int a[],int n,int low,int high)
{
    if(high<low)
    return a[0];
    
    if(high==low)
    return a[low]
    
    int mid=(low+high)/2;
    
    /*If mid+1 is the min*/
    if(mid<high && a[mid+1]<a[mid])
    return a[mid+1];
    
    if(mid>low && a[mid]<arr[mid-1])
    return a[mid];
    
    if(arr[high]>arr[mid])
    return min(a,n,low,mid-1);
    return min(a,n,mid+1,high);
}
    
