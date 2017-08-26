#include<stdio.h>

struct node
{
    int data;
    struct node* next;
};

struct node* reverseK(struct node* head,int k)
{
    struct node* cur=head;
    struct node* next;
    struct node *prev=NULL;
    int count=0;

    while(cur!=NULL && count<k)
    {
        //printf("\ncur=%d \n",cur->data);
       next=cur->next;
       cur->next=prev;
       prev=cur;
       cur=next;
       count++;
    }

    if(next!=NULL)
    {head->next=reverseK(next,k);}

    return prev;
}

void push(struct node **head,int data)
{
    struct node *nd=(struct node*)malloc(sizeof(struct node));
        nd->data=data;
    nd->next=*head;
    (*head)=nd;
}

void printList(struct node* head)
{
    struct node* cur=head;

    while(cur!=NULL)
    {
        printf("%d ",cur->data);
        cur=cur->next;
    }
    printf("\n\n");
}

int main()
{
    struct node *head=NULL;
    push(&head, 8);
     push(&head, 7);
     push(&head, 6);
     push(&head, 5);
     push(&head, 4);
     push(&head, 3);
     push(&head, 2);
     push(&head, 1);
    printList(head);
    head=reverseK(head,3);
    printList(head);
    return 0;
}
