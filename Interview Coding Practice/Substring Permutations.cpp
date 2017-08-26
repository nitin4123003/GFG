#include<iostream.h>
using namespace std;
#include<conio.h>

int main()
{
    char s[100],t[100];
    int i,j,k,l,flag;
    gets(s);
    gets(t);
    int sums,sumt;
    int lens=strlen(s);
    int lent=strlen(t);
    for(i=0;i<lent;i++)
    sumt+=t[i];
    for(i=0;i<lens;i++)
    {
        sums=0;
        for(j=i;j<i+lent;j++)
        sums+=s[j];
        if(sums==sumt)
        {
            for(k=0;k<lent;k++)
            {
                for(l=0;l<lent;l++)
                {
                    flag=0;
                    if(s[i+k]==t[l])
                    {
                        flag=1;
                        break;
                    }
                }
                if(!flag)
                break;
            }
            if(flag)
            {
                printf("%d\t",i);
                i=i+lent-1;
            }
        }
    }
    getch();
}
