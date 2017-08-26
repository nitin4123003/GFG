#include<stdio.h>

struct ListNode
{
    int data;
    struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode *l1,struct ListNode *l2)
{
    int carry=0;
    struct ListNode* result=(struct ListNode*)malloc(sizeof(struct ListNode));
    result->next=NULL;
    struct ListNode *last=result->next;
    while(l1!=NULL && l2!=NULL)
    {
        int sum=carry+l1->data+l2->data;

        int digit=sum%10;
        carry=sum>=10?1:0;
        //printf("sum is %d\n",digit);
        struct ListNode* nd=(struct ListNode*)malloc(sizeof(struct ListNode));
        nd->data=digit;
        nd->next=NULL;

        if(result->next==NULL)//If it is the first ListNode
        {
            result->next=nd;
            last=nd;
        }

        last->next=nd;
        last=nd;
        l1=l1->next;
        l2=l2->next;
    }

    if(carry)
    {
        struct ListNode* last=result;
        while(last->next!=NULL)
            last=last->next;

        struct ListNode *newListNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newListNode->data=carry;
        newListNode->next=NULL;
        last->next=newListNode;
    }

    return result;
}

void insert(struct ListNode** head,int data)
{
    struct ListNode *newListNode=(struct ListNode*)malloc(sizeof(struct ListNode));
    newListNode->data=data;
    newListNode->next=(*head)->next;
    (*head)->next=newListNode;
}

void printList(struct ListNode* head)
{
    struct ListNode* cur=head->next;
    while(cur!=NULL)
    {
        printf("%d ",cur->data);
        cur=cur->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode* head1=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* head2=(struct ListNode*)malloc(sizeof(struct ListNode));
    head1->next=NULL;
    head2->next=NULL;
    insert(&head1,3);
    insert(&head1,4);
    insert(&head1,2);

    insert(&head2,4);
    insert(&head2,6);
    insert(&head2,5);

    printList(head1);
    printList(head2);
    struct ListNode *result=addTwoNumbers(head1->next,head2->next);

    printList(result);
}
