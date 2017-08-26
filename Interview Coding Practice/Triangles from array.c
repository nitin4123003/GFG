#include<stdio.h>
#include<conio.h>

/* Quicksort Function*/
void quicksort(int a[],int p,int r)
{
     int q;
     if(p<r)
     {
            q=partition(a,p,r);
            quicksort(a,p,q-1);
            quicksort(a,q+1,r);
     }
}


/* Partition Function*/
int partition(int A[],int p,int r)
{
     int x,temp=0,i,j;
     x=A[r];
     i=p-1;
     for(j=p;j<=r-1;j++)
     {
                       if(A[j]<=x)
                       {
                                  i=i+1;
                                  temp=A[i];
                                  A[i]=A[j];
                                  A[j]=temp;
                       }
     }
     temp=A[i+1];
     A[i+1]=A[r];
     A[r]=temp;
     return(i+1);
}


int main()
{
    int a[7]={10,21,22,100,101,200,300};
    int n=7,i,k,j,count=0;
    quicksort(a,0,n-1);
    for(i=0;i<n-2;i++)
    {
        for(j=i+1;j<n;j++)
        {
            for(k=i+2;k<n &&(a[i]+a[j]>a[k]);k++){}
            count+=k-j-1;
        }
    }
    printf("%d",count);
    getch();
}
