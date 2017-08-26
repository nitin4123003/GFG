#include<stdio.h>
#define MAX 100
int stack[MAX];
int top=-1;

void push(int num)
{
    if(top<MAX-1)
    stack[++top]=num;
    else
    printf("OVERFLOW\n");
}

int pop()
{
    if(top<0)
    {
        printf("UNDERFLOW\n");
        return -1;
    }
    else
    return stack[top--];
}

int main()
{
    int num,i,element;
    int arr[]={4, 5, 2, 25};
    int n=sizeof(arr)/sizeof(arr[0]);
    push(arr[0]);
    for(i=1;i<n;i++)
    {
        int next=arr[i];
        if(top!=-1)
        {
            element=pop();
            while(element<next)
            {
                printf("%d-->%d\n",element,next);
                element=pop();
            }
            if(element>next)
            push(element);
        }
        push(next);
        //printf("TOP=%d\n\n",top);
    }
    for(i=0;i<=top;i++)
    printf("%d-->-1\n",stack[i]);
}
