#include<stdio.h>
#include<limits.h>

int max(int a,int b)
{
    return a>b?a:b;
}
int maxCut(int arr[],int l,int n)
{
    if(l<=0 ||n==0)
    return 0;

    return max(maxCut(arr,l,n-1),arr[n-1]+maxCut(arr,l-n,n));

}
int main()
{
    int arr[]={1, 5, 8, 9, 10, 17, 17, 20};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("%d",maxCut(arr,8,n));
}
