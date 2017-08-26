#include<stdio.h>
#define MAX_SIZE 100
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/*void inOrder(struct node *nd)
{
    if(nd==NULL)
    return;

    inOrder(nd->left);
    printf("%d ",nd->data);
    inOrder(nd->right);

}*/

struct node* newNode(int data)
{
    struct node* nd=(struct node*)malloc(sizeof(struct node));
    nd->data=data;
    nd->left=NULL;
    nd->right=NULL;
    return nd;
}

struct node* stack[MAX_SIZE];
int top=0;

void inOrder(struct node* root)
{
    int done=0;
    struct node *curr=root;
    while(!done)
    {
        if(curr!=NULL)
        {
            stack[top++]=curr;
            curr=curr->left;
            printf("left data=%d\n ",curr->data);
        }
        else
        {
            if(top!=0)
            {
                struct node *popped=stack[--top];
                printf("%d ",popped->data);
                curr=curr->right;
                printf("right data=%d\n ",curr->data);
            }
            else
                done=1;
        }
    }
}

int main()
{
    struct node* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    inOrder(root);
    return 0;
}
