#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *npx;
};

struct node* XOR(struct node *a,struct node* b)
{
    return ((struct node*) ((unsigned int)(a) ^ (unsigned int)(b)) );
}

void insert(struct node** head_ref,int data)
{
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;

    new_node->npx=XOR(*head_ref,NULL);

    if(*head_ref!=NULL)
    {
        struct node *next=XOR((*head_ref)->npx,NULL);
        (*head_ref)->npx=XOR(new_node,next);
    }

    *head_ref=new_node;
}

void printList(struct node *head)
{
    struct node* prev=NULL;
    struct node* curr=head;
    struct node* next;
    while(curr!=NULL)
    {
        printf("%d ",curr->data);
        next=XOR(prev,curr->npx);
        prev=curr;
        curr=next;
    }
}

int main()
{
    struct node *head=NULL;
    insert(&head,40);
    insert(&head,50);
    insert(&head,60);
    insert(&head,70);
    insert(&head,80);

    printList(head);
    return 0;
}
