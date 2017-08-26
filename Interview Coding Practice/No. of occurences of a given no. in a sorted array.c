#include<stdio.h>
#include<conio.h>

int main()
{
    int a[]={1,2,4,4,4,4,4,4,5,6,7};
    int n=sizeof(a)/sizeof(a[0]);
    int num=4;
    int i=bsSearch(a,0,n-1,num);
    int j=beSearch(a,0,n-1,num,n);
    printf("%d",j-i+1);
    getch();
}

int bsSearch(int a[],int low,int high,int num)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        /*printf("%d\t%d\t%d\n",low,high,mid);*/
        if(mid==0 && a[mid]==num)
        return 0;
        else if(a[mid]==num && a[mid-1]<a[mid])
        return mid;
        else if(a[mid]>=num)
        return bsSearch(a,low,mid-1,num);
        else if(a[mid]<num)
        return bsSearch(a,mid+1,high,num);
    }
    return -1;
}
    
int beSearch(int a[],int low,int high,int num,int n)
{
    while(high>=low)
    {
        int mid=(low+high)/2;
        /*printf("%d\t%d\t%d\n",low,high,mid);*/
        if(mid==n-1||(a[mid]==num && a[mid]<a[mid+1]))
        return mid;
        else if(a[mid]<=num)
        return beSearch(a,mid+1,high,num,n);
        else if(a[mid]>num)
        return beSearch(a,low,mid-1,num,n); 
    }
    return -1;
}
