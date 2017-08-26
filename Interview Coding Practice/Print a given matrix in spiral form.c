#include<stdio.h>
#define R 1
#define C 5

void spiralPrint(int a[R][C],int k,int l,int m,int n)
{
    int i;

    if(k<=m && l<=n)
    {
        //Print the first row
        for(i=l;i<=n;i++)
        printf("%d\t",a[k][i]);

        //Print the last column
        for(i=k+1;i<=m;i++)
        printf("%d\t",a[i][n]);

        if(k!=m)
        {
            //Print the last row
            for(i=n-1;i>=l;i--)
            printf("%d\t",a[m][i]);
        }

        if(l!=n)
        {
            //Print the first column
            for(i=m-1;i>k;i--)
            printf("%d\t",a[i][l]);
        }

        spiralPrint(a,++k,++l,--m,--n);
    }
}

int main()
{
    int arr[R][C]={{1,4,7,10,13}};
    spiralPrint(arr,0,0,R-1,C-1);
}
