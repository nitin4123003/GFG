#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int comp(const void *a,const void *b)
{
    return (*(int*)a>*(int*)b);
}

int count(int a[],int n)
{
    int i,j,k;
    int count=0;
    qsort(a,n,sizeof(a[0]),comp);
    
    for(i=0;i<n-2;i++)
    {
        int k=i+2;
        for(j=i+1;j<n-1;j++)
        {
            while(a[i]+a[j]>a[k] && k<n)
            k++;
            count+=k-j-1;
        }
    }
    return count;
}

int main()
{
    int a[]={4,6,3,7};
    int n=sizeof(a)/sizeof(a[0]);
    printf("No. of possible Triangles =%d",count(a,n));
    getch();
}
