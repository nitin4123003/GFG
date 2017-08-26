#include<iostream>
using namespace std;
#include<algorithm>
#include<sstream>
int main()
{
    int n,i,j;
    cin>>n;
    stringstream ss;
    ss<<n;
    string s;
    ss>>s;
    cout<<s<<endl;
    int flag=0;
    for(i=s.length()-1;i>0;i--)
    {
        for(j=i-1;j>=0;j--)
        {
            if(s[i]-48>s[j]-48)
            {
                flag=1;
                break;
            }
        }
        if(flag)
            break;
    }
    if(i==0)
        cout<<-1;
    else{
    char temp=s[i];
    s[i]=s[j];
    s[j]=temp;
    cout<<s<<endl;
    cout<<i<<" "<<j<<endl;
    sort(s.begin()+j+1,s.end());
    cout<<s<<endl;
    }
}
