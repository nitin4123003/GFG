#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int getHeight(struct node *nd)
{
    if(nd==NULL)
    return 0;

    else
    {
        int lHeight=getHeight(nd->left);
        int rHeight=getHeight(nd->right);

        if(lHeight<rHeight)
        return (lHeight+1);
        else
        return (rHeight+1);
    }
}

void printSpiral(struct node *root)
{
    int i;
    int height=getHeight(root);
    //printf("height=%d\n\n",height);

    int ltr=0;
    for(i=1;i<=height;i++)
    {
        printLevel(root,i,ltr);
        ltr=1-ltr;
    }
}

void printLevel(struct node *root,int level,int ltr)
{

    if(root==NULL)
    return;

    if(level==1)
    printf("%d ",root->data);
    else if(level>1)
    {
        if(ltr)
        {
            printLevel(root->left,level-1,ltr);
            printLevel(root->right,level-1,ltr);
        }
        else
        {
            printLevel(root->right,level-1,ltr);
            printLevel(root->left,level-1,ltr);
        }
    }
}

struct node* newNode(int data)
{
    struct node *nd=(struct node*)malloc(sizeof(struct node));
    nd->data=data;
    nd->left=NULL;
    nd->right=NULL;
    return nd;
}

int main()
{
    struct node *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
    printf("Spiral Order traversal of binary tree is \n");
    printSpiral(root);
}
