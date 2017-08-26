#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

struct node* reverseK(struct node *head,int k)
{
        struct node* prev,next,prev_start,start;
        struct node* cur;
        prev=NULL;
        cur=head;
        prev_start=NULL;
        struct node* new_head;
        while(1)
        {
            int i=0;
            start=cur;
            while(i<k && cur!=NULL)
            {
                next=cur->next;
                cur->next=prev;
                prev=cur;
                cur=next;
                i++;
            }
            if(prev_start==NULL)
            new_head=prev;
            if(prev_start!=NULL)
            prev_start->next=prev;
            prev_start=start;
        }
        return  new_head;
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

    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);


    struct node* ptr=reverseK(head,3);
    printList(ptr);
    getchar();
    return 0;
}
