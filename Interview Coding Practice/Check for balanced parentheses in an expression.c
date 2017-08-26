#include<stdio.h>
#define MAX 100
char arr[MAX];
int top=-1;
void push(char c)
{
    if(top<MAX-1)
    arr[++top]=c;
    else
    printf("OVERFLOW\n");
}

char pop()
{
    if(top<0)
    printf("UNDERFLOW\n");
    else
    return arr[top--];
}

int matchPair(char c,char d)
{
    if(c=='[' && d==']'||c=='{' && d=='}'||c=='(' && d==')')
    return 1;
    else return 0;
}

int checkIsBalanced(char str[])
{
    int i;

    for(i=0;i<strlen(str);i++)
    {
        if(str[i]=='['||str[i]=='{'||str[i]=='(')
        push(str[i]);
        else if(str[i]==']'||str[i]=='}'||str[i]==')')
        {
            char d=pop();
            int result=matchPair(d,str[i]);
            if(result==0)
            return 0;
        }
    }
    return 1;
}

int main()
{
    char str[]="“[(])";
    printf("%d",checkIsBalanced(str));
}
