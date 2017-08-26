#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* newNode(int data)
{
    struct node* nd=(struct node*)malloc(sizeof(struct node));
    nd->data=data;
    nd->next=NULL;
    return nd;
}

void insert(struct node **head,int data)
{
    struct node *nd=newNode(data);
    struct node *temp=*head;
    *head=nd;
    nd->next=temp;
}

void delete(struct node *node_ptr)
{
    struct node *temp=node_ptr->next;
    node_ptr->data=temp->data;
    node_ptr->next=temp->next;
}

void printList(struct node *head)
{
    struct node *node_ptr=head;
    while(node_ptr!=NULL)
    {
        printf("%d\t",node_ptr->data);
        node_ptr=node_ptr->next;
    }
    printf("\n");
}

int main()
{
    struct node *head=NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    insert(&head,5);

    printList(head);
    delete(head->next);
    printList(head);
    delete(head);
    printList(head);

    return 0;
}
