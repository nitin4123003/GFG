#include<stdio.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* nd=(struct node*)malloc(sizeof(struct node));
    nd->data=data;
    nd->left=NULL;
    nd->right=NULL;
    return nd;
}

int isSumProperty(struct node* nd)
{
    int left_data=0,right_data=0;

    if(nd==NULL || nd->left==NULL && nd->right==NULL)//NULL and Leaf nodes
        return 1;

    if(nd->left!=NULL)
        left_data=nd->left->data;
    if(nd->right!=NULL)
        right_data=nd->right->data;

    if((left_data+right_data==nd->data) && (isSumProperty(nd->left)) && (isSumProperty(nd->right)))
        return 1;

    else
        return 0;
}

int main()
{
    struct node *root  = newNode(10);
  root->left         = newNode(8);
  root->right        = newNode(2);
  root->left->left   = newNode(3);
  root->left->right  = newNode(5);
  root->right->right = newNode(2);
  if(isSumProperty(root))
    printf("The given tree satisfies the children sum property ");
  else
    printf("The given tree does not satisfy the children sum property ");

    return 0;


}
