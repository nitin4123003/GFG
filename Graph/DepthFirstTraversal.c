#include<stdio.h>

int stack[100];
int top=0;
void DFS(int adj[][6],int V,int start)
{
    int visited[6]={0};
    int i,j;

    stack[top++]=start;
    printf("%d ",start+1);
    int cur=start;
    while(top!=-1)
    {
        int flag=0;
        for(i=0;i<V;i++)


        {
            if(adj[cur][i]==1 && visited[i]==0)
            {
                stack[top++]=i;
                visited[i]=1;
                printf("%d ",i+1);
                flag=1;
                cur=i;
                break;
            }
        }
        if(flag==0)
        {
            int popped=stack[--top];
            //printf("top=%d and popped=%d \n",top,popped+1);
            cur=popped;
        }
    }
}

int main()
{
    int ADJ[][6]={{0,1,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,1,1},{0,1,0,0,0,0},{0,0,0,1,0,0},{0,0,0,0,0,1}};
    int start=2;
    int V=6;
    DFS(ADJ,V,start);
}
