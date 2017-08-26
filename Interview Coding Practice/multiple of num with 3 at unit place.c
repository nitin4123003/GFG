#include<stdio.h>
#include<conio.h>
int main()
{
    int num,n,i;
    scanf("%d",&n);
    num=1;
    for(i=0;num%n!=0;i++)
    num=num*10+1;
    printf("%d",num);
    getch();
}
