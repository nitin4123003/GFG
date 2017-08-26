#include<stdio.h>

int findMax(int a[],int n)
{
    int i,max_val=-1;;
    for(i=0;i<n;i++)
    {
        if(max_val<a[i])
        max_val=a[i];
    }
    return max_val;
}

int findMin(int a[],int n)
{
    int i,min_val=32567;;
    for(i=0;i<n;i++)
    {
        if(min_val>a[i])
        min_val=a[i];
    }
    return min_val;
}

int main()
{
    int flag1=0,flag2=0;
    int arr[]={7, 6, 5, 5, 3, 4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int max=findMax(arr,n);
    int min=findMin(arr,n);
    if(max-min+1==n)
    flag1=1;

    if(flag1)
    {
        //Find condition 2
        int *visited=(int*)calloc(n,sizeof(int));
        int i;

        for(i=0;i<n;i++)
        {
            if((visited[arr[i]-min])==1)
            flag2==1;
            visited[arr[i]-min]=1;
            printf("%d\n",visited[i]);
        }
    }
    printf("%s",(flag1==1 && flag2==0)?"YES":"NO");
    return 0;
}

