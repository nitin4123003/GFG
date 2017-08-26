#include<stdio.h>

struct node
{
    int data;
    struct node* next;
};

void pairWiseSwap(struct node **head)
{

    if(*head==NULL ||(*head)->next==NULL)
    return;

    struct node *cur=(*head)->next;
    struct node *prev=*head;
    struct node *next;

    *head=cur;

    while(1)
    {
        next=cur->next;
        cur->next=prev;

        if(next==NULL || next->next==NULL)
        {
            prev->next=next;
            break;
        }

        prev->next=next->next;
        prev=next;
        cur=next->next;
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
    struct node *start = NULL;

    /* The constructed linked list is:
     1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);

    printf("\n Linked list before calling  pairWiseSwap() ");
    printList(start);

    pairWiseSwap(&start);

    printf("\n Linked list after calling  pairWiseSwap() ");
    printList(start);

    getchar();
    return 0;
}
