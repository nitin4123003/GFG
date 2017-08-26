#include<iostream>
using namespace std;

int main()
{
    int i,flag,n;
    cin>>n;
    string s;
    cin>>s;
    string shift="ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
    int s_len=shift.length();
    for(i=0;i<s.length()/2;i++)
    {
        char temp=s[i];
        s[i]=s[s.length()-1-i];
        s[s.length()-1-i]=temp;
    }
    //cout<<s<<endl;
    for(i=0;i<s.length();i++)
    {
        if(s[i]>=65 && s[i]<=90)
            s[i]=shift[(s[i]-65+n)%28];
        else if(s[i]=='_')
            s[i]=shift[(26+n)%28];
        else if(s[i]=='.')
            s[i]=shift[(27+n)%28];
    }
    cout<<s;

}
