#include<stdio.h>

struct pair
{
    int max;
    int min;
};

struct pair getMinMax(int a[],int n)
{
    int i=0;
    struct pair minmax;

    if(n%2==0)//Even no. of elements
    {
        if(a[i]<a[i+1])
        {
            minmax.min=a[i];
            minmax.max=a[i+1];
        }
        else
        {
            minmax.min=a[i+1];
            minmax.max=a[i];
        }
        i=2;
    }

    if(n%2!=0)//Odd no. of elements
    {
        minmax.min=a[i];
        minmax.max=a[i];
        i=1;
    }

    while(i<n)
    {
        if(a[i]<a[i+1])
        {
            if(minmax.min>a[i])
            minmax.min=a[i];
            if(minmax.max<a[i+1])
            minmax.max=a[i+1];
        }
        else
        {
            if(minmax.min>a[i+1])
            minmax.min=a[i+1];
            if(minmax.max<a[i])
            minmax.max=a[i];
        }
        i+=2;
    }
    return minmax;
}

int main()
{
    int arr[]={1000, 11, 445, 1, 330, 3000};
    int n=sizeof(arr)/sizeof(arr[0]);
    struct pair minmax=getMinMax(arr,n);
    printf("MAX=%d  MIN=%d\n",minmax.max,minmax.min);
}
