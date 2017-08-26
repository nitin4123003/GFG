#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compare(const void *a,const void *b)
{
    return (*(char*)a - *(char*)b);
}

void swap(char *a,char *b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}

int findCeil(char str[],char first,int low,int high)
{
    int i;
    int ceilIndex=low;
    for(i=low+1;i<high;i++)
    {
        if(str[i]>first && str[i]<str[ceilIndex])
        ceilIndex=i;
    }
    return ceilIndex;
}

void sortedPermutations(char str[])
{
    int i;
    int len=strlen(str);
    qsort(str,len,sizeof(char),compare);

    int isFinished=0;

    while(!isFinished)
    {
        printf("%s\n",str);

        for(i=len-2;i>=0;i--)
        {
            if(str[i]<str[i+1])
            break;
        }

        if(i==-1)
        isFinished=1;
        else
        {
            int ceil=findCeil(str,str[i],i+1,len);

            swap(&str[i],&str[ceil]);

            qsort(str+i+1,len-i-1,sizeof(str[0]),compare);
        }
    }
}

int main()
{
    char str[]="ABCD";
    sortedPermutations( str );
    return 0;
}
