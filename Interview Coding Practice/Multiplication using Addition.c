#include<conio.h>
#include<stdio.h>
int main()
{
    int i,sum=0;
    int a,b;
    scanf("%d%d",&a,&b);
    int min=a<b?a:b;
    int grt=(min==a)?b:a;
    for(i=0;i<min;i++)
    sum+=grt;
    printf("%d",sum);
    getch();
}
