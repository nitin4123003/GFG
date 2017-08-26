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

void doubleTree(struct node *root)
{
    if(root==NULL)
    {
        //printf("reached null\n");
        return;
    }
    //printf("here=%d\n",root->data);
    doubleTree(root->left);
    doubleTree(root->right);

    struct node* temp=root->left;
    struct node *nd=newNode(root->data);
    root->left=nd;
    nd->left=temp;
}

void inOrder(struct node *nd)
{
    if(nd==NULL)
    return;

    inOrder(nd->left);
    printf("%d ",nd->data);
    inOrder(nd->right);

}

int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    inOrder(root);
    doubleTree(root);
    printf("\n\n");
    inOrder(root);
    return 0;
}
