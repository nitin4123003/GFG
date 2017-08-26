#include<stdio.h
#include<stdlib.h>

struct AdjListNode
{
    int dest;
    struct AdjListNode *next;
};

struct AdjList
{
    struct AdjListNode *head;
};

struct Graph
{
    int V;
    struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* nd=(struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    nd->dest=dest;
    nd->next=NULL;
    return nd;
}

struct Graph* createGraph(int v)
{
    struct Graph* newGraph=(struct Graph*)malloc(sizeof(struct Graph));
    newGraph->V=v;

    newGraph->array=(struct AdjList*)malloc(v*sizeof(struct AdjList));

    int i;
    for(i=0;i<v;i++)
    newGraph->array[i].head=NULL;

    return newGraph;
}

void addEdge(struct Graph* graph,int src,int dest)
{
    struct AdjListNode* nd=newAdjListNode(dest);
    nd->next=graph->array[src].head;
    graph->array[src].head=nd;

    //Since graph is undirected add an edge from dest to source also
    nd=newAdjListNode(src);
    nd->next=graph->array[dest].head;
    graph->array[dest].head=nd;
}

void printGraph(struct Graph *graph)
{
    int i;
    for(i=0;i<graph->V;i++)
    {
        printf("%d\t",i);
        struct AdjListNode *cur=graph->array[i].head;
        while(cur!=NULL)
        {
            printf("%d\t",cur->dest);
            cur=cur->next;
        }
        printf("\n");
    }
}

int main()
{
    int V=5;
    struct Graph *graph=createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);
    return 0;
}
