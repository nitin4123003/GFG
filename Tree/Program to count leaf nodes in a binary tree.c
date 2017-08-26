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

int countLeaf(struct node* nd)
{

    if(nd==NULL)
        return 0;

    else if(nd->left==NULL && nd->right==NULL)
        return 1;

    else
    {
        int count;
        count=countLeaf(nd->left)+countLeaf(nd->right);
        return count;
    }
}

int main()
{
    struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

  /*get leaf count of the above created tree*/
  printf("Leaf count of the tree is %d", countLeaf(root));
  return 0;

}
