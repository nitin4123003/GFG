#include<stdio.h>

struct node
{
    int data;
    struct node* next;
};

int detectLoop(struct node* head)
{
    struct node* slow_ptr=head;
    struct node* fast_ptr=head;

    while(slow_ptr && fast_ptr && fast_ptr->next)
    {
        slow_ptr=slow_ptr->next;
        fast_ptr=fast_ptr->next->next;

        if(slow_ptr==fast_ptr)
        {
            removeLoop(slow_ptr,head);
            return 1;
        }
    }

    return 0;
}

void removeLoop(struct node* loop_node,struct node* head)
{
    struct node* ptr1=head;
    struct node* ptr2;

    while(1)
    {
        ptr2=loop_node;

        while(ptr2->next!=loop_node && ptr2->next!=ptr1)
        {
            ptr2=ptr2->next;
        }

        if(ptr2->next==ptr1)
        break;

        else
        ptr1=ptr1->next;
    }

    ptr2->next=NULL;
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
    struct node* head = NULL;

    push(&head, 10);
    push(&head, 4);
    push(&head, 15);
    push(&head, 20);
    push(&head, 50);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    //printList(head);
    detectLoop(head);

    printf("Linked List after removing loop \n");
    printList(head);

    getchar();
    return 0;
}
