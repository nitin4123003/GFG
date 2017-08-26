#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,temp;
    int b[4][4];
    int a[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        b[j][i]=a[i][j];
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        printf("%d\t",b[i][j]);
        printf("\n");
    }
    for(i=0;i<4;i++)
    {
        for(j=3;j>=0;j--)
        printf("%d\t",b[i][j]);
        printf("\n");
    }
    getch();
}
