#include<stdio.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct node* newNode(char data)
{
    struct node* nd=(struct node*)malloc(sizeof(struct node));
    nd->data=data;
    nd->left=NULL;
    nd->right=NULL;
    return nd;
}

void printPostOrder(struct node* nd)
{
    if(nd==NULL)
        return ;

    printPostOrder(nd->left);
    printPostOrder(nd->right);
    printf("%c\t",nd->data);
}

void printInOrder(struct node* nd)
{
    if(nd==NULL)
        return ;

    printInOrder(nd->left);
    printf("%c\t",nd->data);
    printInOrder(nd->right);
}

void printPreOrder(struct node* nd)
{
    if(nd==NULL)
        return ;

    printf("%c\t",nd->data);
    printPreOrder(nd->left);
    printPreOrder(nd->right);
}

int main()
{
    struct node *root=newNode('-');
    root->left=newNode('+');
    root->left->left=newNode('9');
    root->left->right=newNode('5');
    root->right=newNode('2');

    printPreOrder(root);
    printf("\n");
    printInOrder(root);
    printf("\n");
    printPostOrder(root);
    printf("\n");
    return 0;
}
