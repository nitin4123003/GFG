#include<iostream>
using namespace std;
#include<climits>
int main()
{
    string s="1523457";
    int max_count=INT_MIN;
    int i;
    for(i=0;i<s.length();i++)
    {
        int count=1;
        int left_sum=0;
        int right_sum=0;
        while(i-count>=0 && i+count-1<s.length())
        {
            left_sum+=(s[i-count]-48);
            right_sum+=(s[i+count-1]-48);
            //cout<<i<<" "<<left_sum<<" "<<right_sum<<endl;

            if(left_sum==right_sum && max_count<2*count)
            max_count=2*count;
            count++;
        }
    }
    if(max_count==INT_MIN)
        cout<<0<<endl;
    else
        cout<<max_count;
}
