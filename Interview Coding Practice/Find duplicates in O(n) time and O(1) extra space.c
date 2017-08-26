#include<stdio.h>

void findDuplicates(int arr[],int n)
{
    int i,x;

    for(i=0;i<n;i++)
    {
        if(arr[i]>=n)
        arr[i]-=n;

        x=arr[i];

        if(arr[abs(x)]>0)
        arr[abs(x)]=-arr[abs(x)];
        else
        {
            printf("%d\n",abs(arr[i]));
            arr[abs(x)]=n-arr[abs(x)];
        }
    }
}

int main()
{
    int arr[]={4,2,3,3,3,3,1,4,5,6,1,2,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    findDuplicates(arr,n);
    return 0;
}
