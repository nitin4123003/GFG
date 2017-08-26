#include<stdio.h>
#include<stdlib.h>
int stack1[1000];
char stack2[1000];
int id1=0,id2=0;
int main()
{
    char exp[]="1+(3*2)+4";
    char num[10];
    int i,j=0;
    int a,b;
    char oprtr;
    for(i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='(');
        else if(isdigit(exp[i]) && isdigit(exp[i+1]))
        {
            num[j++]=exp[i];
            //printf("Start=%c",num[j-1]);
        }
        else if(isdigit(exp[i]) && !(isdigit(exp[i+1])))
        {
            num[j++]=exp[i];
            num[j]='\0';
            //printf("Comp=%s exp=%c",num,exp[i]);
            stack1[id1++]=atoi(num);
            //printf("Stack 1=%d\n\n",stack1[id1-1]);
            memset(&num[0],0, sizeof(num));
            j=0;
        }
        else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/')
        {
            stack2[id2++]=exp[i];
            //printf("Stack2=%c\n",stack2[id2-1]);
        }
        else if(exp[i]==')')
        {
            b=stack1[--id1];
            a=stack1[--id1];
            //printf("%d and %d",a,b);
            oprtr=stack2[--id2];
            if(oprtr=='+')
            stack1[id1++]=a+b;
            else if(oprtr=='-')
            stack1[id1++]=a-b;
            else if(oprtr=='*')
            stack1[id1++]=a*b;
            else if(oprtr=='/')
            stack1[id1++]=a/b;
            //printf("Pushed in Stack 1=%d\n\n",stack1[id1-1]);
        }
    }
    printf("%d",stack1[--id1]);
    return 0;
}
