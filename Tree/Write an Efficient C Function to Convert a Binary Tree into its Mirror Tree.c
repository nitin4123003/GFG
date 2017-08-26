#include<stdio.h>

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
}

void mirror(struct node *nd)
{
    if(nd==NULL)
    return;

    mirror(nd->left);
    mirror(nd->right);

    struct node *temp=nd->left;
    nd->left=nd->right;
    nd->right=temp;
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
    struct node *root=newNode(1);

    root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

    /* Print inorder traversal of the input tree */
  printf("\n Inorder traversal of the constructed tree is \n");
  inOrder(root);

  /* Convert tree to its mirror */
  mirror(root);

  /* Print inorder traversal of the mirror tree */
  printf("\n Inorder traversal of the mirror tree is \n");
  inOrder(root);

  getchar();
  return 0;
}
