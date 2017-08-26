#include<stdio.h>
int main()
{
    int a[]={45,1,24,14,34,4};
    int n=sizeof(a)/sizeof(a[0]);
    int i,key,j;
    for(j=1;j<n;j++)
    {
        key=a[j];
        i=j-1;
        while(i>=0 && key<a[i])
        {
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    }

    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
}
