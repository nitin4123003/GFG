#include<stdio.h>
int findMin(int a[],int n,int *index)
{
    int i;
    int min_val=32567;
    for(i=0;i<n;i++)
    {
        if(a[i]<min_val)
        {
            min_val=a[i];
            *index=i;
        }
    }
}

void findKMax(int a[],int n,int temp[],int k)
{
    int i;
    int index=0;
    int min_val=findMin(temp,k,&index);
    //printf("INDEX=%d\n",index);

    for(i=k;i<n;i++)
    {
        if(a[i]>min_val)
        {
            temp[index]=a[i];
            min_val=findMin(temp,k,&index);
        }
    }
}

int main()
{
    int arr[]={23,1, 12, 9, 30, 2, 50};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i,k=3;
    int temp[3];
    for(i=0;i<k;i++)
    temp[i]=arr[i];
    findKMax(arr,n,temp,k);
    for(i=0;i<k;i++)
    printf("%d\t",temp[i]);
}
