#include<iostream.h>
using namespace std;
#include<conio.h>

int main()
{
    int arr[]={2,3,3,5,3,4,1,7},i,index=0,n=8,k=8,max=arr[0];
    for(i=0;i<n;i++)
    arr[arr[i]%k]+=k;
    for(i=0;i<n;i++)
    cout<<arr[i]<<endl;
    for(i=1;i<n;i++)
    {
        if(max<arr[i])
        max=arr[index=i];
    }
    cout<<"\n"<<index;
    getch();
}
