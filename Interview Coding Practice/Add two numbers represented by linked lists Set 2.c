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

struct node* add(struct node* head1,struct node* head2,int *carry)
{
    if(head1==NULL)
        return NULL;
    struct node* result=(struct node*)malloc(sizeof(struct node));
    result->next=add(head1->next,head2->next,carry);
    int sum=head1->data+head2->data+*carry;
    *carry=sum/10;
    sum=sum%10;
    result->data=sum;
    printf("sum is %d\n",result->data);

    return result;
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
    struct node* head1=(struct node*)malloc(sizeof(struct node));
    struct node* head2=(struct node*)malloc(sizeof(struct node));
    head1->next=NULL;
    head2->next=NULL;
    insert(&head1,1);
    insert(&head1,2);
    insert(&head1,3);

    insert(&head2,4);
    insert(&head2,5);
    insert(&head2,6);

    printList(head1);
    printList(head2);
    int carry=0;
    struct node* head3=(struct node*)malloc(sizeof(struct node));
    head3->next=add(head1->next,head2->next,&carry);
    printList(head3);

    return 0;
}
