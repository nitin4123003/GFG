#include<stdio.h>
int max(int a,int b)
{
    return(a>b?a:b);
}

int min(int a,int b)
{
    return(a<b?a:b);
}

int findDiff(int arr[],int n)
{
    int *LMin=(int*)malloc(n*sizeof(int));
    int *RMax=(int*)malloc(n*sizeof(int));
    int i,j,max_diff;

    LMin[0]=arr[0];
    for(i=1;i<n;i++)
    LMin[i]=min(LMin[i-1],arr[i]);

    RMax[n-1]=arr[n-1];
    for(i=n-2;i>=0;i--)
    RMax[i]=max(arr[i],RMax[i+1]);

    i=0,j=0,max_diff=-1;
    while(i<n && j<n)
    {
        if(LMin[i]<RMax[j])
        {
            max_diff=max(max_diff,j-i);
            j=j+1;
        }
        else
        i++;
    }

    return max_diff;
}

int main()
{
    int array[]={9, 2, 3, 4, 5, 6, 7, 8, 18, 0};
    int n=sizeof(array)/sizeof(array[0]);
    int max_value=findDiff(array,n);
    printf("%d",max_value);
    return 0;
}
