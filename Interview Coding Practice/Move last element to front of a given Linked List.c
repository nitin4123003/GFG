#include<stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node* newNode(int data)
{
    struct node* nd=(struct node *)malloc(sizeof(struct node));
    nd->data=data;
    nd->next=NULL;
    return nd;
}

void move(struct node** head)
{
    struct node* node_ptr=(*head)->next;
    struct node* second_last;
    while(node_ptr->next!=NULL)
    {
        second_last=node_ptr;
        node_ptr=node_ptr->next;
    }
    //printf("%d and %d",second_last->data,node_ptr->data);
    second_last->next=NULL;
    node_ptr->next=(*head)->next;
    (*head)->next=node_ptr;
}

void insert(struct node** head,int data)
{
    struct node* nd=newNode(data);
    struct node* temp=(*head)->next;
    (*head)->next=nd;
    nd->next=temp;
}

void printList(struct node *head)
{
    struct node *node_ptr=head->next;
    while(node_ptr!=NULL)
    {
        printf("%d\t",node_ptr->data);
        node_ptr=node_ptr->next;
    }
    printf("\n");
}

int main()
{
    struct node* head=(struct node*)malloc(sizeof(struct node));
    head->next=NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    insert(&head,5);

    printList(head);
    move(&head);
    printList(head);

    return 0;
}
