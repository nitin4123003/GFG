#include<stdio.h>

struct node
{
    int data;
    struct node* next;
};

void recursiveReverse(struct node** head_ref)
{
    struct node* first;
    struct node* rest;

    /* empty list */
    if (*head_ref == NULL)
       return;

    /* suppose first = {1, 2, 3}, rest = {2, 3} */
    first = *head_ref;
    rest  = first->next;

    /* List has only one node */
    if (rest == NULL)
       return;

    /* reverse the rest list and put the first element at the end */
    recursiveReverse(&rest);
    first->next->next  = first;

    /* tricky step -- see the diagram */
    first->next  = NULL;

    /* fix the head pointer */
    *head_ref = rest;
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
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 85);
    printList(head);
    recursiveReverse(&head);
    printList(head);
    return 0;
}


