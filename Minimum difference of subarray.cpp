#include<iostream>
using namespace std;
#include<vector>
#include<climits>

int min(int a,int b)
{
    return a<b?a:b;
}

int minDiff(int sum,vector<int> arr,int n,int elm)
{
    if(arr[n]>sum)
    return minDiff(sum,arr,n-1,elm);
    if(elm==0)
    return sum;
    if(n<0)
    return INT_MAX;
    return min(minDiff(sum-arr[n],arr,n-1,elm-1),minDiff(sum,arr,n-1,elm));
}

int main()
{
    vector<int> arr;
    int elem,i;
    int arr_size;
    cin>>arr_size;
    for(i=0;i<arr_size;i++)
        {
            cin>>elem;
            arr.push_back(elem);
        }
    //for(i=0;i<arr.size();i++)
    //    cout<<arr[i]<<" ";
    int n=arr.size();
    int sum=0;
    for(i=0;i<arr.size();i++)
    sum=sum+arr[i];
    int minn=minDiff(sum/2,arr,n-1,n/2);
    cout<<endl<<minn;
}
