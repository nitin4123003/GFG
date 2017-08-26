#include<stdio.h>
int r,c;
void spiralPrint(int a[r][c],int k,int l,int m,int n,char ch)
{
    int i;

    if(k<=m && l<=n)
    {
        //Print the first row
        for(i=l;i<=n;i++)
        a[k][i]=ch;

        //Print the last column
        for(i=k+1;i<=m;i++)
        a[i][n]=ch;

        if(k!=m)
        {
            //Print the last row
            for(i=n-1;i>=l;i--)
            a[m][i]=ch;
        }

        if(l!=n)
        {
            //Print the first column
            for(i=m-1;i>k;i--)
            a[i][l]=ch;
        }

        char x=(ch=='X')?'0':'X';
        spiralPrint(a,++k,++l,--m,--n,x);
    }
}

int main()
{
    int i,j;
    printf("Enter the no. of rows and columns");
    scanf("%d%d",&r,&c);
    int arr[r][c];
    spiralPrint(arr,0,0,r-1,c-1,'X');
    // Print the filled matrix
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%c ", arr[i][j]);
        printf("\n");
    }
}
