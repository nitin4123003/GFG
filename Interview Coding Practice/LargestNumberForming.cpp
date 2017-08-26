#include<iostream>
using namespace std;
#include<string.h>
#include<vector.h>
#include<conio.h>


int myCompare(string x,string y)
{
    string xy=x.append(y);
    string yx=y.append(x);
    return (x.compare(y)?1:0);
}

void formNumber(vector<string> arr)
{
    sort(arr.begin(),arr.end(),myCompare);
    for(int i=0;i<arr.size();i++)
    cout<<arr[i];    
}

int main()
{
    vector<string> arr;
    
    arr.push_back("54");
    arr.push_back("546");
    arr.push_back("548");
    arr.push_back("60");
    
    formNumber(arr);
    getch();
    return 0;
}
