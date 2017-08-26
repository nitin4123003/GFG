#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data)
{
    struct node *nd=(struct node*)malloc(sizeof(struct node));
    nd->data=data;
    nd->left=NULL;
    nd->right=NULL;
    return nd;
}

int isLeaf(struct node* root)
{
    if(root==NULL)
    return 0;
    if(root->left==NULL && root->right==NULL)
    return 1;

    return 0;
}

int isSumTree(struct node *nd)
{
    if(nd==NULL ||isLeaf(nd))
    return 1;

    int ls,rs;

    if(isSumTree(nd->left) && isSumTree(nd->right))
    {
        //Get the sum of nodes in left sub tree
        if(nd->left==NULL)
        ls=0;
        else if(isLeaf(nd->left))
        ls=nd->left->data;
        else
        ls=2*(nd->left->data);

        //Get the sum of nodes in right sub tree
        if(nd->right==NULL)
        rs=0;
        else if(isLeaf(nd->right))
        rs=nd->right->data;
        else
        rs=2*(nd->right->data);

        return (nd->data==ls+rs);
    }

    return 0;
}

int main()
{
    struct node *root  = newNode(26);
    root->left         = newNode(10);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(6);
    root->right->right = newNode(3);

    if(isSumTree(root))
    printf("The given tree is a sum tree\n");
    else
    printf("The given tree is a not sum tree\n");
    return 0;
}
