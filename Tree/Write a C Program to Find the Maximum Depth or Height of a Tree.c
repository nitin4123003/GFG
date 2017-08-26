#include<stdio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data)
{
    struct node *nw=(struct node*)malloc(sizeof(struct node));
    nw->data=data;
    nw->left=NULL;
    nw->right=NULL;
    return nw;
}

int maxDepth(struct node* node)
{
    if(node==NULL)
        return 0;

    else
    {
        int lDepth=maxDepth(node->left);
        int rDepth=maxDepth(node->right);

        if(lDepth>rDepth)
            return (lDepth+1);
        else
            return (rDepth+1);

    }
}

int main()
{
    struct node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Height of tree is %d", maxDepth(root));

    getchar();
    return 0;
}


