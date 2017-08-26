#include<stdio.h>
#include<conio.h>
int main()
{
    int a[]={1,12,27,34,76,83};
    int i=5,j=5,n=6;
    int num=64;
    while((a[j]-a[i])!=num && i<=j)
    {
        if((a[j]-a[i])<num)
        i--;
        else if((a[j]-a[i])>num)
        j--;
        printf("%d\t%d\n",i,j);
    }
    printf("Indices %d and %d have the given difference",i,j);
    getch();
}
    
