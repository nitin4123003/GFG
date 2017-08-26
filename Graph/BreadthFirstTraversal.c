#include<stdio.h>

int queue[100];
int front=0,rear=0;

void bfs(int adj[][6],int V,int start)
{
    int i;
    int visited[6]={0};
    queue[rear++]=start;
    visited[start]=1;
    while(front!=rear)
    {
        int popped=queue[front++];
        printf("%d ",popped+1);
        for(i=0;i<V;i++)
        {
            if(adj[popped][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                queue[rear++]=i;
            }
        }
    }
}

int main()
{
    int ADJ[][6]={{0,1,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,1,1},{0,1,0,0,0,0},{0,0,0,1,0,0},{0,0,0,0,0,1}};
    int start=2;
    int V=6;
    bfs(ADJ,V,start);
}
