#include<stdio.h>
#include<conio.h>
int main()
{
    int a[]={1,1,2,3,2};
    int i;
    int n=sizeof(a)/sizeof(a[0]);
    for(i=0;i<n;i++)
    {
        if(a[abs(a[i])]<0)
        printf("%d\n",abs(a[i]));
        else
        a[abs(a[i])]=-a[abs(a[i])];
    }
    getch();
}
