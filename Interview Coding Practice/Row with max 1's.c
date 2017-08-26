#include<stdio.h>
#include<conio.h>
#define N 5

int bsearch(int a[N],int low,int high)
{
    if(high>=low)
    {
        int mid=(low+high)/2;
        
        if((mid==0||a[mid-1]==1) && a[mid]==0)
        return mid;
        else if(a[mid]==1)
        return bsearch(a,mid+1,high);
        else if(a[mid]==0)
        return bsearch(a,low,mid-1);
    }
    return 0;
}

void findMax(int a[][N])
{
    int i,max=0,row=0,num;
    for(i=0;i<N;i++)
    {
        if(a[i][N-1]==1)
        num=5;
        else
        num=bsearch(a[i],0,N-1);
        printf("number of 1's in %d row=%d\n",i+1,num);
        if(num>max)
        {
            max=num;
            row=i;
        }
    }
    printf("The row with max. no. of 1's is %d\n",row+1);
}

int main()
{
    int a[][N]={{1,1,1,0,0},{1,1,1,1,1},{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0}};
    findMax(a);
    getch();
}
