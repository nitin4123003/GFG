#include<stdio.h>
#include<stdlib.h>
struct Edge
{
    int src,dest,weight;
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

int myComp(void *a,void *b)
{
    struct Edge* a1=(struct Edge*)a;
    struct Edge *b1=(struct Edge*)b;
    return a1->weight > b1->weight;
}

void KruskalMST(struct Graph *graph)
{
    int V=graph->V;
    struct Edge result[V];
    int e=0;
    int i;

    //Step1:sort the edges
    qsort(graph->edge,graph->E,sizeof(graph->edge[0]),myComp);

    //Create subsets array
    struct subset *subsets=(struct subset*)malloc(V*sizeof(struct subset));
    for(i=0;i<V;i++)
    {
        subsets[i].parent=i;
        subsets[i].rank=0;
    }

    int eg_index=0;
    while(e<V-1)//while the no. of edges to be included in the spanning tree is not V-1
    {
        struct Edge next_edge=graph->edge[eg_index++];

        int x=find(subsets,next_edge.src);
        int y=find(subsets,next_edge.dest);

        if(x!=y)
        {
            result[e++]=next_edge;
            Union(subsets,x,y);
        }
    }

    printf("Following is the MST for the given graph\n");
    for(i=0;i<e;i++)
    printf("Edge from %d to %d with weight=%d\n",result[i].src,result[i].dest,result[i].weight);
}

int main()
{
    /* Let us create following weighted graph
             10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
            4       */
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    struct Graph* graph = createGraph(V, E);


    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    KruskalMST(graph);

    return 0;
}
