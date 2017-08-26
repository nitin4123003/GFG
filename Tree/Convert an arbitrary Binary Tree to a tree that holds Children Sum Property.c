#include<stdio.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int mod(int n)
{
    if(n>0)
        return n;
    else
        return (-1*n);
}

struct node* newNode(int data)
{
    struct node* nd=(struct node*)malloc(sizeof(struct node));
    nd->data=data;
    nd->left=NULL;
    nd->right=NULL;
    return nd;
}

void increment(struct node* nd)
{
    if(nd->left==NULL && nd->right==NULL)
        return;
    else
    {
        int diff=nd->data-(nd->left->data+nd->right->data);

        if(diff>0)
        nd->data+=mod(diff);
        else if(diff<0)
        {
            nd->data+=mod(diff);
            increment(nd->left);
        }
    }
}

void postOrder(struct node* root)
{
    increment(root->left);
    increment(root->right);
    increment(root);
}

void printInorder(struct node* root)
{
    printInorder(root->left);
    printf("%d ",root->data);
    printInorder(root->right);
}

int main()
{
    struct node *root = newNode(50);
    root->left        = newNode(7);
    root->right       = newNode(2);
    root->left->left  = newNode(3);
    root->left->right = newNode(5);
    root->right->left  = newNode(1);
    root->right->right = newNode(30);

    printf("\n Inorder traversal before conversion ");
    printInorder(root);

    postOrder(root);

    printf("\n Inorder traversal after conversion ");
    printInorder(root);

    return 0;
}
