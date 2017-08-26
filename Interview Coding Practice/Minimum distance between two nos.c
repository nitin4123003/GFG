#include<stdio.h>
#include<conio.h>
#include<limits.h>

void findRepeat(int a[],int n,int x,int y)
{
    int i,prev;
    int min=INT_MAX;
    for(i=0;i<n;i++)
    {
        if(a[i]==x||a[i]==y)
        {
            prev=i;
            break;
        }
    }
    
    for(i=prev;i<n;i++)
    {
        if(a[i]==x||a[i]==y)
        {
            if(a[i]!=a[prev] && i-prev<min)
            {
                min=i-prev;
                prev=i;
            }
            else
            prev=i;
        }
    }
    printf("%d",min);
}


int main()
{
    int a[]={3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3};
    int n=sizeof(a)/sizeof(a[0]);
    int x=3,y=6;
    findRepeat(a,n,x,y);
    getch();
}
