#include<stdio.h>
#include<conio.h>

void printRepeat(int a[],int size)
{
    int i,xor=a[0],x=0,y=0;
    int n=size-2;
    for(i=1;i<size;i++)
    xor=xor^a[i];
    for(i=1;i<=n;i++)
    xor=xor^i;
    
    int rightbit=xor & ~(xor-1);
    
    for(i=0;i<size;i++)
    {
        if(a[i]&rightbit)
        x=x^a[i];
        else
        y=y^a[i];
    }
    
    for(i=1;i<=n;i++)
    {
        if(rightbit&i)
        x=x^i;
        else
        y=y^i;
    }
    printf("The two repetitions are %d\t%d",x,y);
}

int main()
{
    int a[]={4,2,4,5,2,3,1};
    int n=sizeof(a)/sizeof(a[0]);
    printRepeat(a,n);
    getch();
}
