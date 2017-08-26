#include<iostream>
using namespace std;


int smallestSubWithSum(int arr[],int n,int x)
{
    int i;
    int start=0;

    int curr_sum=arr[0];
    int min_len=n+1;

    for(i=1;i<n;i++)
    {
        while(curr_sum>x && start<i)
        {
            if(i-start<min_len)
            min_len=i-start;

            curr_sum=curr_sum-arr[start++];
        }


        curr_sum=curr_sum+arr[i];
    }
    return min_len;
}

int main()
{
    int arr1[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    cout << smallestSubWithSum(arr1, n1, x) << endl;

    int arr2[] = {1, 10, 5, 2, 7};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    x  = 9;
    cout << smallestSubWithSum(arr2, n2, x) << endl;

    int arr3[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    x  = 280;
    cout << smallestSubWithSum(arr3, n3, x);

    return 0;
}
