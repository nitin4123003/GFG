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
    return nd;
}

void printPaths(struct node *nd)
{
    int path[100];
    printPathRecur(nd,path,0);
}

void printArray(int path[100],int pathLen)
{
    int i;
    for(i=0;i<pathLen;i++)
    printf("%d-",path[i]);
    printf("END\n");
}

void printPathRecur(struct node *nd,int path[100],int pathLen)
{

    if(nd==NULL)
    return;

    path[pathLen++]=nd->data;

    //a leaf node
    if(nd->left==NULL && nd->right==NULL)
    {
        printArray(path,pathLen);
    }

    printPathRecur(nd->left,path,pathLen);
    printPathRecur(nd->right,path,pathLen);

}

int main()
{
    struct node *root=newNode(1);
    root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

  /* Print all root-to-leaf paths of the input tree */
  printPaths(root);

  getchar();
  return 0;
}
