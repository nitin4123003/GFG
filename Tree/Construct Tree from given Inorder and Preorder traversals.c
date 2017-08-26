#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int search(char [],int,int,char);
struct node* newNode(int data)
{
    struct node *nd=(struct node*)malloc(sizeof(struct node));
    nd->data=data;
    nd->left=NULL;
    nd->right=NULL;
    return nd;
}

struct node* buildTree(char in[],char pre[],int inStart,int inEnd)
{
    static int preIndex=0;

    if(inStart>inEnd)
    return NULL;

    struct node* nd=newNode(pre[preIndex++]);

    if(inStart==inEnd)
        return nd;

    int inIndex=search(in,inStart,inEnd,nd->data);

    nd->left=buildTree(in,pre,inStart,inIndex-1);
    nd->right=buildTree(in,pre,inIndex+1,inEnd);

    return nd;
}

int search(char in[],int inStart,int inEnd,char data)
{
    int i;
    for(i=inStart;i<=inEnd;i++)
    {
        if(data==in[i])
        return i;
    }
}

void inOrder(struct node *nd)
{
    if(nd==NULL)
    return;

    inOrder(nd->left);
    printf("%c ",nd->data);
    inOrder(nd->right);

}

int main()
{
  char in[] = "DBEAFC";
  char pre[] = "ABDECF";
  int len = sizeof(in)/sizeof(in[0]);
  struct node *root = buildTree(in, pre, 0, len - 1);

  /* Let us test the built tree by printing Inorder traversal */
  printf("\n Inorder traversal of the constructed tree is \n");
  inOrder(root);
  getchar();
}
