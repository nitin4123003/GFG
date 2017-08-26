#include<stdio.h>

struct node
{
    int data;
    struct node* next;
};

struct node* reverseAltK(struct node* head,int k)
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

    if(head!=NULL)
    head->next=cur;

    count=0;
    while(count<k-1 && cur!=NULL)
    {
        cur=cur->next;
        count++;
    }

    if(cur!=NULL)
    {cur->next=reverseAltK(cur->next,k);}

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
    int i;
    struct node *head=NULL;
    for(i = 20; i > 0; i--)
      push(&head, i);

    printList(head);
    head=reverseAltK(head,3);
    printList(head);
    return 0;
}
