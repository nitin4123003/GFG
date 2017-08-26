#include<stdio.h>
#include<conio.h>

void printNonRepeat(int a[],int n)
{
    int xor=a[0];
    int i,x=0,y=0;
    for(i=1;i<n;i++)
    xor=xor^a[i];
    
    int rightBit=xor&~(xor-1);
    
    for(i=0;i<n;i++)
    {
        if(rightBit&a[i])
        x=x^a[i];
        else
        y=y^a[i];
    }
    printf("The two non repeating no.s are %d\t%d",x,y);
}
    
int main()
{
    int a[]={2,4,7,5,2,4,5,10};
    int n=sizeof(a)/sizeof(a[0]);
    printNonRepeat(a,n);
    getch();
}
