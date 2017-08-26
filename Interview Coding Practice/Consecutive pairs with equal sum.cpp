#include<iostream.h>
#include<conio.h>
using namespace std;
int main()
{
    int a[]={1,5,7,8,9,10};
    int b[]={2,3,3,5,6,11};
    int p=6,q=6;
    int i=0,j=0,sum1=-1,sum2=1;
    while(i<p-1 && j<q-1)
    {
        sum1=a[i]+a[i+1];
        sum2=b[j]+b[j+1];
        if(sum1==sum2)
        {
            cout<<a[i]<<"\t"<<a[i+1]<<"\t"<<b[j]<<"\t"<<b[j+1]<<endl;
            i++;
            j++;
        }
        else if(sum1<sum2)
        i++;
        else 
        j++;
    }
    getch();
}
    
