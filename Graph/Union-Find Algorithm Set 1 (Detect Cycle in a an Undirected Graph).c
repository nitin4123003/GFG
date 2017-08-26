#include<stdio.h>

struct Edge
{
    int src;
    int dest;
};

struct Graph
{
    int V,E;
    struct Edge* edge;
};

struct Graph* createGraph(int V,int E)
{
    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->V=V;
    graph->E=E;

    graph->edge=(struct Edge*)malloc(E*sizeof(struct Edge));;
    return graph;
}

int find(int parent[],int i)
{
    if(parent[i]==-1)
    return i;

    find(parent,parent[i]);
}

void Union(int parent[],int x,int y)
{
    int xSet=find(parent,x);
    int ySet=find(parent,y);

    parent[xSet]=ySet;
}

int isCycle(struct Graph *graph)
{
    int *parent=(int*)malloc(graph->V*sizeof(int));
    memset(parent,-1,graph->V*sizeof(int));

    int i;
    for(i=0;i<graph->E;i++)
    {
        int x=find(parent,graph->edge[i].src);
        int y=find(parent,graph->edge[i].dest);

        if(x==y)
            return 1;
        Union(parent,x,y);
    }
    return 0;
}

int main()
{
    struct Graph* graph = createGraph(3, 3);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;

    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;

    if(isCycle(graph))
        printf("The graph contains cycle\n");
    else
        printf("The graph does not contain any cycle");

    return 0;
}
