#include<stdio.h>
#include<stdlib.h>
int precedence(char a,char b)
{
    int i;
    char order[]={'(','-','+','*','/'};
    if(b=='(')
        return 1;
    else if(a=='-' && b=='+'||a=='+' && b=='-')
        return 1;
    else if()
}

int main()
{
    printf("ans=%d\n",precedence('*','+'));
    char exp[]="2-1+3*4/2";
    int stack1[20];
    char stack2[20];
    int top1=0,top2=0;
    int flag=0;
    int i=0;
    while(i<strlen(exp))
    {
        char num[10];
        int j=0;
        if(isdigit(exp[i]) && isdigit(exp[i+1]))
        num[j++]=exp[i];
        else if(isdigit(exp[i]) && !isdigit(exp[i+1]))
        {
            num[j++]=exp[i];
            num[j]='\0';
            stack1[top1++]=atoi(num);
        }
        if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/')
        {
            if(top2!=0 && precedence(exp[i],stack2[top2-1]))
            {
                //printf("YA");
                int b=stack1[--top1];
                int a=stack1[--top1];
                printf("\n\na=%db=%d\n\n",a,b);
                char oprtr=stack2[--top2];
                if(oprtr=='+')
                stack1[top1++]=a+b;
                else if(oprtr=='-')
                stack1[top1++]=a-b;
                else if(oprtr=='*')
                stack1[top1++]=a*b;
                else if(oprtr=='/')
                stack1[top1++]=a/b;
                printf("stack1=%d\n",stack1[top1-1]);
            }

            stack2[top2++]=exp[i];
        }

        /*if(exp[i]==')')
        {
            while(stack2[top2]!='(')
            {
                int b=stack1[--top1];
                int a=stack1[--top1];

                char oprtr=stack2[--top2];
                if(oprtr=='+')
                stack1[top1++]=a+b;
                else if(oprtr=='-')
                stack1[top1++]=a-b;
                else if(oprtr=='*')
                stack1[top1++]=a*b;
                else if(oprtr=='/')
                stack1[top1++]=a/b;
            }
        }*/
        i++;


        printf("s1=%d,s2=%c\n",stack1[top1-1],stack2[top2-1]);

    }
    printf("top2=%d\n",top2);
    while(top2>0)
    {
        int b=stack1[--top1];
        int a=stack1[--top1];

        char oprtr=stack2[--top2];
        if(oprtr=='+')
        stack1[top1++]=a+b;
        else if(oprtr=='-')
        stack1[top1++]=a-b;
        else if(oprtr=='*')
        stack1[top1++]=a*b;
        else if(oprtr=='/')
        stack1[top1++]=a/b;
        printf("s1=%d,s2=%c\n",stack1[top1-1],stack2[top2-1]);
    }
    printf("ans=%d\n",stack1[top1-1]);
}
