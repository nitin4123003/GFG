#include<stdio.h>

int findCount(int a[],int n)
{
    int c[3]={0};
    int i;
    for(i=0;i<n;i++)
    c[a[i]%3]++;

    int count_2=0,count_3=0;
    //Count the no. of groups of 2
    count_2+=(c[0]*(c[0]-1))/2;
    count_2+=c[1]*c[2];

    //Count the no. of groups of 3
    count_3+=(c[0]*(c[0]-1)*(c[0]-2))/6;
    count_3+=(c[1]*(c[1]-1)*(c[1]-2))/6;
    count_3+=(c[2]*(c[2]-1)*(c[2]-2))/6;
    count_3+=c[0]*c[1]*c[2];

    return (count_3+count_2);
}

int main()
{
    int arr[]={3, 6, 7, 2, 9};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("%d",findCount(arr,n));
    return 0;
}
