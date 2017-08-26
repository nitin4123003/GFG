#include<stdio.h>

int compare(const void *a,const void *b)
{
    return (*(char*)a-*(char*)b);
}

void allLexicographicRecur(char str[],char data[],int last,int index)
{
    int i;
    int len=strlen(str);
    for(i=0;i<len;i++)
    {
        data[index]=str[i];

        if(index==last)
            printf("%s\n",data);
        else
            allLexicographicRecur(str,data,last,index+1);
    }
}

void allLexicographicStr(char str[])
{
    int len=strlen(str);
    char *data=(char*)malloc((len+1)*sizeof(char));
    data[len]='\0';
    qsort(str,len,sizeof(char),compare);
    allLexicographicRecur(str,data,len-1,0);
    free(data);
}

int main()
{
    char str[]="ABC";
    allLexicographicStr(str);
    return 0;
}
