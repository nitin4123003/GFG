#include<stdio.h>

void segregate(int a[],int n)
{
    int i=0,j=n-1;
    int temp;
    while(i<j)
    {
        if(a[i]>0 && a[j]<=0)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
            j--;
        }
        if(a[i]<=0)
        i++;
        if(a[j]>0)
        j--;
    }
}

int findMissingPositive(int a[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        if(abs(a[i])-1<n && a[abs(a[i])-1]>0)
            a[abs(a[i])-1]=-a[abs(a[i])-1];

    }
    for(i=0;i<n;i++)
    {
        if(a[i]>0)
            return i+1;
    }

    return n+1;
}

int main()
{
    int arr[]={1, 1, 0, -1, -2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=0;
    segregate(arr,n);
    //for(i=0;i<n;i++)
    //printf("%d\t",arr[i]);
    while(arr[i]<=0)
        i++;
    printf("MISSING POSITIVE=%d",findMissingPositive(arr+i,n-i));
    return 0;
}
