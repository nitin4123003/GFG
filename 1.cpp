#include<iostream>
using namespace std;

int main()
{
    int t,i,j,flag,n;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    cin>>arr[i];
    for(i=2;;i++)
    {
        flag=0;
        int hash[10];
        for(j=0;j<=9;j++)
        hash[j]=-1;
        for(j=0;j<n;j++)
        hash[arr[j]%i]++;
        for(j=0;j<9;j++)
        {
            if(hash[j]>=1)
            {
                flag=1;
                break;
            }
        }
        if(!flag)
        break;
    }
    cout<<i;

}
