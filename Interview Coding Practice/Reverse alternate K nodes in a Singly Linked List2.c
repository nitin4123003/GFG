#include<stdio.h>

struct node
{
    int data;
    struct node* next;
};

struct node* reverseAltK_(struct node* nd,int k,int b);
struct node* reverseAltK(struct node* head,int k)
{
    return reverseAltK_(head,k,1);
}

struct node* reverseAltK_(struct node* nd,int k,int b)
{
    if(nd==NULL)
    return NULL;

    struct node* cur=nd;
    struct node* next;
    struct node *prev=NULL;
    int count=0;

    while(cur!=NULL && count<k)
    {
        //printf("\ncur=%d \n",cur->data);
       next=cur->next;

       if(b==1)
        cur->next=prev;
       prev=cur;
       cur=next;
       count++;
    }

    if(b==1)
    {
        nd->next=reverseAltK_(cur,k,1-b);
        return prev;
    }

    else
    {
        prev->next=reverseAltK_(cur,k,1-b);
        return nd;
    }
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
