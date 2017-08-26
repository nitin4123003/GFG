#include<stdio.h>
void merge(int mPlusN[],int N[],int m,int n)
{
    int i,j,k;
    i=n;
    j=0;
    k=0;
    while(k<m+n)
    {
        if((i<m+n && mPlusN[i]<=N[j]) || j==n)
        {
            mPlusN[k]=mPlusN[i];
            i++;
            k++;
        }
        else
        {
            mPlusN[k]=N[j];
            j++;
            k++;
        }
    }
}

void printArray(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d  ",arr[i]);
}

void moveToEnd(int mPlusN[],int m)
{
    int i;
    int j=m-1;
    for(i=m-1;i>=0;i--)
    {
        if(mPlusN[i]!=-1)
        {
            mPlusN[j]=mPlusN[i];
            j--;
        }
    }
}

int main()
{
    int mPlusN[]={2, 8, -1,-1, -1, 13, -1, 15, 20};
    int N[]={5, 7, 9, 25};
    int n=sizeof(N)/sizeof(N[0]);
    int m=(sizeof(mPlusN)/sizeof(mPlusN[0]))-n;
    moveToEnd(mPlusN,m+n);
    int i;
    printArray(mPlusN,m+n);
    printf("\n\n\n\n");
    merge(mPlusN,N,m,n);
    printArray(mPlusN,m+n);
}
