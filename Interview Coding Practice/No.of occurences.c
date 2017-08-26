#include<stdio.h>
#include<conio.h>
int main()
{
    int a[7]={1,2,2,3,3,3,3};
    int n=sizeof(a)/sizeof(a[0]);
    int c=count(a,n,3);
    printf("%d",c);
    getch();
}

int count(int a[],int n,int x)
{
    int i,j;
    i=first(a,0,n-1,n,x);
    
    if(i==-1)
    return i;
    
    j=last(a,0,n-1,n,x);
    return j-i+1;
}

int first(int a[],int low,int high,int n,int x)
{
    if(high>=low)
    {
        int mid=(low+high)/2;
    
        if(mid==0||x>a[mid-1] && a[mid]==x)
        return mid;
    
        if(x>a[mid])
        return first(a,mid+1,high,n,x);
        else
        return first(a,low,mid-1,n,x);
    }
    return -1;
}

int last(int a[],int low,int high,int n,int x)
{
    if(high>=low)
    {
        int mid=(low+high)/2;
        
        if(mid==n-1||x<a[mid+1] && a[mid]==x)
        return mid;
        
        if(x<a[mid])
        return last(a,low,mid-1,n,x);
        else
        return last(a,mid+1,high,n,x);
    }
    return -1;
}
