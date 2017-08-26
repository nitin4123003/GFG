#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void bucketSort(float a[],int n)
{
    vector<float> b[n];
    int i,j;

    for(i=0;i<n;i++)
    {
        int bucket_index=n*a[i];
        b[bucket_index].push_back(a[i]);
    }

    for(i=0;i<n;i++)
    sort(b[i].begin(),b[i].end());

    int index=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<b[i].size();j++)
            a[index++]=b[i][j];
    }
}

int main()
{
    float arr[]={0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n=sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr,n);

    cout<<"Sorted array using bucket sort is\n";
    int i;
    for(i=0;i<n;i++)
        cout<<arr[i]<<"\t";
}
