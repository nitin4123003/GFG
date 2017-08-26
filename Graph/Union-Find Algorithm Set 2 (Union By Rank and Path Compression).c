#include<stdio.h>

struct Edge
{
    int src,dest;
};

struct Graph
{
    int V,E;
    struct Edge *edge;
};

struct subset
{
    int parent;
    int rank;
};

struct Graph* createGraph(int V,int E)
{
    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->V=V;
    graph->E=E;

    graph->edge=(struct Edge*)malloc(E*sizeof(struct Edge));
    return graph;
}

int find(struct subset subsets[],int i)
{
    if(subsets[i].parent!=i)
        subsets[i].parent=find(subsets,subsets[i].parent);

    return subsets[i].parent;
}

void Union(struct subset subsets[],int x,int y)
{
    int xRoot=find(subsets,x);
    int yRoot=find(subsets,y);

    //Attach tree with less depth to the root of the tree with greater depth
    if(subsets[xRoot].rank<subsets[yRoot].rank)
    subsets[xRoot].parent=yRoot;
    else if(subsets[xRoot].rank>subsets[yRoot].rank)
    subsets[yRoot].parent=xRoot;
    else
    {
        subsets[yRoot].parent=xRoot;
        subsets[xRoot].rank++;
    }
}

int isCycle(struct Graph *graph)
{
    int V=graph->V;
    int E=graph->E;

    struct subset *subsets=(struct subsets*)malloc(V*sizeof(struct subset));

    int i;
    for(i=0;i<V;i++)
    {
        subsets[i].parent=i;
        subsets[i].rank=0;
    }

    for(i=0;i<E;i++)
    {
        int x=find(subsets,graph->edge[i].src);
        int y=find(subsets,graph->edge[i].dest);

        if(x==y)
        return 1;

        Union(subsets,x,y);
    }

    return 0;

}

int main()
{
    int V=3,E=3;
    struct Graph *graph=createGraph(V,E);

    graph->edge[0].src=0;
    graph->edge[0].dest=1;
    graph->edge[1].src=1;
    graph->edge[1].dest=2;
    graph->edge[2].src=2;
    graph->edge[2].dest=0;

    if(isCycle)
    printf("The graph contains a cycle\n");
    else
    printf("The graph does not contain a cycle");

    return 0;
}
