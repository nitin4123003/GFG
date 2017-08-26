#include<stdio.h>
#define MAX_SIZE 100

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int front,rear;

struct node** createQueue();
void enqueue(struct node**,struct node*  );
struct node* dequeue(struct node** );
struct node* newNode(int );
void printLevelOrder(struct node*);


struct node** createQueue()
{
    struct node** queue=(struct node**)malloc(sizeof(struct node*)*MAX_SIZE);
    front=0;
    rear=0;
    return queue;
}

void enqueue(struct node **queue,struct node* temp)
{
    queue[rear++]=temp;
}

struct node* dequeue(struct node** queue)
{
    return queue[front++];
}

struct node* newNode(int data)
{
    struct node *nd=(struct node*)malloc(sizeof(struct node));
    nd->data=data;
    nd->left=NULL;
    nd->right=NULL;
    return nd;
}

void printLevelOrder(struct node *root)
{
    struct node *queue=createQueue();
    struct node *temp=root;

    while(temp!=NULL)
    {
        printf("%d ",temp->data);

        if(temp->left)
            enqueue(queue,temp->left);

        if(temp->right)
            enqueue(queue,temp->right);

        temp=dequeue(queue);
    }
}

int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    printf("Level Order traversal of binary tree is \n");
    printLevelOrder(root);
    return 0;
}
