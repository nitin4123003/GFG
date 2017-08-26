#include<iostream.h>
#include<conio.h>
using namespace std;
int main()
{
    int a[]={1,4,0,0,3,10,5};
    int i=0,j=0,csum=0,n=7;
    int sum=7;
    while(i<n && j<n)
    {
        while(csum<sum && j<n)
        csum+=a[j++];
        while(csum>sum && i<n)
        csum-=a[i++];
        if(csum==sum)
        {
            printf("Sum found between %d and %d",i,j-1);
            break;
        }
    }
    if(i==n||j==n)
    printf("not found\n");
    getch();
}
        
