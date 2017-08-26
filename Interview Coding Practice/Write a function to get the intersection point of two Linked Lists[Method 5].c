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

void reverse(struct node** head)
{
    struct node* prev=NULL;
    struct node* cur=(*head)->next;
    //printf("data is %d",cur->data);
    struct node* next;
    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    (*head)->next=prev;
}

int findIntersection(struct node* head1,struct node* head2)
{
    int count1=getCount(head1);
    int count2=getCount(head2);

    reverse(&head1);
    printList(head1);
    int count3=getCount(head1)-1;
    //printf("\n\n%d %d %d\n",count1,count2,count3);
    int x=(count1+count3-count2)/2;
    int y=(count2+count3-count1)/2;
    int z=(count1+count2-count3)/2;
    reverse(&head1);
    int cont=0;
    struct node* node_ptr=head1->next;
    while(cont<3)
    {
        cont++;
        node_ptr=node_ptr->next;
    }
    return node_ptr->data;
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
