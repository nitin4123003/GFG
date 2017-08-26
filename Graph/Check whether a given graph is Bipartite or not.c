#include<stdio.h>
#define V 4
int queue[100];
int front=0,rear=0;

int isBipartite(int G[][V],int src)
{
    int i;
    int *colorArr=(int*)malloc(V*sizeof(int));
    memset(colorArr,-1,V*sizeof(int));

    queue[rear++]=src;
    colorArr[src]=1;

    while(front!=rear)
    {
        int cur=queue[front++];

        for(i=0;i<V;i++)
        {
            if(G[cur][i]==1 && colorArr[i]==-1)
            {
                colorArr[i]=1-colorArr[cur];
                queue[rear++]=i;
            }
            else if(G[cur][i]==1 && colorArr[cur]==colorArr[i])
            return 0;
        }
    }
    return 1;
}

int main()
{
    int G[][V] = {{0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    isBipartite(G,0)?printf("Yes"):printf("No");
    return 0;
}

