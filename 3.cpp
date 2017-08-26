#include<iostream>
using namespace std;

int coin_ways(int arr[],int m,int n)
{
    int i,j,x,y;
    int table[n+1][m];
    for(i=0;i<m;i++)
    table[0][i]=1;

    for(i=1;i<n+1;i++)
    {
        for(j=0;j<m;j++)
        {
            x=(i-arr[j]>=0)?table[i-arr[j]][j]:0;
            y=(j>=1)?table[i][j-1]:0;
            table[i][j]=x+y;
        }
    }
    return table[n][m-1];
}

int main()
{
    int i,m,n;
    cin>>m;
    int arr[m];
    for(i=0;i<m;i++)
        cin>>arr[i];

    cin>>n;
    cout<<coin_ways(arr,m,n);
}
