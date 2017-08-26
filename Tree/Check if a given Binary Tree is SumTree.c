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

int sum(struct node* root)
{
    if(root==NULL)
    return 0;
    else
    return(sum(root->left)+sum(root->right)+root->data);
}

int isSumTree(struct node *nd)
{
    if(nd==NULL||nd->left==NULL && nd->right==NULL)
    return 1;

    int ls=sum(nd->left);
    int rs=sum(nd->right);

    if((ls+rs==nd->data) && isSumTree(nd->left) && isSumTree(nd->right))
    return 1;

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
