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

int getCount(struct node* head)
{
    struct node* node_ptr=head->next;
    int count=0;
    while(node_ptr!=NULL)
    {
        node_ptr=node_ptr->next;
        count++;
    }
    return count;
}

int findIntersection(struct node* head1,struct node* head2)
{
    int count1=getCount(head1);
    int count2=getCount(head2);

    //printf("%d\t%d",count1,count2);
    int diff=abs(count1-count2);
    struct node* greater_list=(count1>count2)?head1:head2;
    struct node* smaller_list=(count1<=count2)?head1:head2;

    struct node* node_ptr1=greater_list->next;
    int count=0;
    while(count<diff)
    {
        node_ptr1=node_ptr1->next;
        count++;
    }
    printf("%d\n",node_ptr1->data);

    struct node* node_ptr2=smaller_list->next;
    while(node_ptr1!=NULL && node_ptr2!=NULL)
    {
        if(node_ptr1==node_ptr2)
            return node_ptr1->data;
        node_ptr1=node_ptr1->next;
        node_ptr2=node_ptr2->next;
    }

    return -1;
}

void insert(struct node** head,int data)
{
    struct node* nd=newNode(data);
    struct node* temp=(*head)->next;
    (*head)->next=nd;
    nd->next=temp;
}

void printList(struct node* head)
{
    struct node* node_ptr=head->next;
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
    head1->next=NULL;
    struct node* head2=(struct node*)malloc(sizeof(struct node));
    head2->next=NULL;
    insert(&head1,9);
    insert(&head1,6);
    insert(&head1,3);
    insert(&head2,30);
    insert(&head2,15);
    insert(&head2,10);
    printList(head1);
    printList(head2);
    head1->next->next->next->next=head2->next->next;
    printList(head1);
    printList(head2);

    printf("The point of intersection of the lists is %d",findIntersection(head1,head2));
    return 0;
}
