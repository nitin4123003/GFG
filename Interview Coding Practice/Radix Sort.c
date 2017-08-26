#include<stdio.h>

int getMax(int arr[],int n)
{
    int max=-1;
    int i;
    for(i=0;i<n;i++)
    {
        if(max<arr[i])
        max=arr[i];
    }
    return max;
}

void countSort(int arr[],int exp,int n)
{
    int count[10]={0};
    int i;
    int *output=(int*)malloc(n*sizeof(int));

    for(i=0;i<n;i++)
    count[(arr[i]/exp)%10]++;

    for(i=1;i<10;i++)
    count[i]+=count[i-1];

    for(i=n-1;i>=0;i--)
    {
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }

    for(i=0;i<n;i++)
    arr[i]=output[i];
}

void radixSort(int arr[],int n)
{
    int max=getMax(arr,n);

    int exp;
    for(exp=1;max/exp>0;exp*=10)
    countSort(arr,exp,n);
}

void print(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    printf("%d ",arr[i]);
}

int main()
{
    int arr[]={170, 45, 75, 90, 802, 24, 2, 66};
    int n=sizeof(arr)/sizeof(arr[0]);
    radixSort(arr,n);
    print(arr,n);
    return 0;
}
