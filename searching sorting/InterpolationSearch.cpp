#include<iostream>
using namespace std;
#include<stdio.h>

int interpolSearch(int arr[],int low,int high,int toFind,int size)
{
    int mid;
    while(arr[low]<=toFind && arr[high]>=toFind)
    {
        mid=low+((toFind-arr[low])*(high-low))/(arr[high]-arr[low]);

        if(arr[mid]==toFind)
        return 1;
        else if(arr[mid]>toFind)
        high=mid-1;
        else
        low=mid+1;
    }
    return 0;
}

int main(){
int array[]={1,2,3,4,5,6,7,8,9,10};
cout<<" "<<(interpolSearch(array,0,9,8,9)?"Found":"Not found")<<endl;
cout<<" "<<(interpolSearch(array,0,9,2,9)?"Found":"Not found")<<endl;
cout<<" "<<(interpolSearch(array,0,9,5,9)?"Found":"Not found")<<endl;
cout<<" "<<(interpolSearch(array,0,9,18,9)?"Found":"Not found")<<endl;
return 0;
}
