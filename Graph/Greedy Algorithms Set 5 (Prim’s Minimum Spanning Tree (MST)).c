#include<stdio.h>
#include<limits.h>

#define V 5

int minKey(int key[],int mstSet[])
{
    int i,index;
    int min=INT_MAX;
    for(i=0;i<V;i++)
    {
        if(key[i]<min && mstSet[i]==0)
        {
            min=key[i];
            index=i;
        }
    }
    return index;
}

void printMST(int parent[],int graph[][V])
{
    int i;
    printf("Edge Weight\n");
    for(i=1;i<V;i++)
    printf("%d----%d with weight %d\n",parent[i],i,graph[i][parent[i]]);
}

void primMST(int graph[][V])
{
    int parent[V];
    int mstSet[V];
    int key[V];
    int i;

    for(i=0;i<V;i++)
    {
        mstSet[i]=0;
        key[i]=INT_MAX;
    }

    parent[0]=-1;
    key[0]=0;

    int count=0;
    while(count<V)
    {
        int u=minKey(key,mstSet);

        mstSet[u]=1;
        for(i=0;i<V;i++)
        {
            if(graph[u][i] && mstSet[i]==0 && graph[u][i]<key[i])
            {
                key[i]=graph[u][i];
                parent[i]=u;
            }
        }
        count++;
    }
    printMST(parent,graph);
}

int main()
{
   /* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
   int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };

    // Print the solution
    primMST(graph);
    return 0;
}
