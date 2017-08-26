#include<stdio.h>
#include<limits.h>
struct nd
{
    int data;
    struct nd* left;
    struct nd* right;
};

typedef struct nd node;

void getTargetLeaf(node *root,int *min,int curr_sum,node **target)
{
    if(root==NULL)
    return;

    int cur_sum=curr_sum+root->data;

    if(root->left==NULL && root->right==NULL)
    {
        if(*min>cur_sum)
        {
            *min=cur_sum;
            *target=root;
        }
    }

    getTargetLeaf(root->left,min,cur_sum,target);
    getTargetLeaf(root->right,min,cur_sum,target);
}

int printPath(node *root,node *targetLeaf)
{
    if(root==NULL)
    return 0;

    if(root==targetLeaf||printPath(root->left,targetLeaf)||printPath(root->right,targetLeaf))
    {
        printf("%d ",root->data);
        return 1;
    }

    return 0;
}

int maxSumPath(node* root)
{
    if(root==NULL)
    return 0;

    int min=INT_MAX;
    node *target_leaf;
    int curr_sum=0;
    getTargetLeaf(root,&min,curr_sum,&target_leaf);
    printPath(root,target_leaf);
    return min;
}

node* newNode(int data)
{
    node* nd=(node*) malloc(sizeof(node));
    nd->data=data;
    nd->left=NULL;
    nd->right=NULL;
    return nd;
}

int main()
{
    node *root = NULL;

    /* Constructing tree given in the above figure */
    root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(4);

    printf ("Following are the nodes on the maximum sum path \n");
    int sum = maxSumPath(root);
    printf ("\nSum of the nodes is %d ", sum);

    getchar();
    return 0;
}
