#include<stdio.h>

struct node
{
    int data;
    struct node* next;
};

struct node* recursivePairWiseSwap(struct node *head)
{

    if(head==NULL ||head->next==NULL)
    return head;

    struct node *remaing=head->next->next;

    struct node *newHead=head->next;
    head->next->next=head;

    head->next=recursivePairWiseSwap(remaing);

    return newHead;
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

    start=recursivePairWiseSwap(start);

    printf("\n Linked list after calling  pairWiseSwap() ");
    printList(start);

    getchar();
    return 0;
}
