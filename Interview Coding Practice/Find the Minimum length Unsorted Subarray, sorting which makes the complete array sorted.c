#include<stdio.h>

int findMax(int arr[],int n,int start,int endd)
{
    int i,max_val=-1;
    for(i=start;i<=endd;i++)
    {
        if(max_val<arr[i])
        max_val=arr[i];
    }
    return max_val;
}

int findMin(int arr[],int n,int start,int endd)
{
    int i,min_val=32567;
    for(i=start;i<=endd;i++)
    {
        if(min_val>arr[i])
        min_val=arr[i];
    }
    return min_val;
}

int main()
{
    int arr[]={0, 1, 15, 25, 6, 7, 30, 40, 50};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i,start=0,endd=n-1;
    for(i=0;i<n;i++)
    {
        if(arr[i]>arr[i+1])
        {
            start=i;
            break;
        }
    }

    for(i=n-1;i>=0;i--)
    {
        if(arr[i-1]>arr[i])
        {
            endd=i;
            break;
        }
    }
    //printf("MAX=%d MIN=%d\n",start,endd);

    int max_elemnt=findMax(arr,n,start,endd);
    int min_elemnt=findMin(arr,n,start,endd);
    //printf("MAX=%d MIN=%d",max_elemnt,min_elemnt);

    for(i=0;i<start;i++)
    {
        if(arr[i]>min_elemnt)
        {
            start=i;
            break;
        }
    }

    for(i=n-1;i>endd;i--)
    {
        if(arr[i]<max_elemnt)
        {
            endd=i;
            break;
        }
    }
    printf("\nMAX=%d MIN=%d",start,endd);
    return 0;
}
