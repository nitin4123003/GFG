#include<iostream.h>
#include<vector.h>
#include<conio.h>
using namespace std;

vector<int> intersec(vector<int> a,vector<int> b)
{
    vector<int> set;
    int n1=a.size();
    int n2=b.size();
    int i=0;
    int j=0;
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        i++;
        else if(a[i]>b[j])
        j++;
        else
        {
            set.push_back(a[i]);
            i++;
            j++;
        }
    }
    return set;
}
    

int main()
{
    vector<int> a(6);
    a.at(0)=1;
    a.at(1)=4;
    a.at(2)=5;
    a.at(3)=9;
    a.at(4)=12;
    a.at(5)=18;
    vector<int> b(4);
    b.at(0)=4;
    b.at(0)=5;
    b.at(0)=9;
    b.at(0)=12;
    vector<int> set=intersec(a,b);
    for(int i=0;i<set.size();i++)
    cout<<set.at(i)<<endl;
    getch();
}
