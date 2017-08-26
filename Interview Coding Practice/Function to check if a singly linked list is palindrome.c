#include<stdio.h>
#include<stdbool.h>

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

int isPalindrome(struct node* head)
{
    struct node* slow_ptr=head;
    struct node* fast_ptr=head;
    struct node* prev_of_slow_ptr=slow_ptr;
    struct node* second_half;
    struct node* middle_node=NULL;
    int result=1;
    while(fast_ptr->next!=NULL && fast_ptr!=NULL)
    {
        prev_of_slow_ptr=slow_ptr;
        slow_ptr=slow_ptr->next;
        fast_ptr=fast_ptr->next->next;
    }

    if(fast_ptr!=NULL)//In the case of odd elements,the middle element would be lost in the palindrome checking.So we have to save it to restore original list.
    {
        middle_node=slow_ptr;
        slow_ptr=slow_ptr->next;
    }

    //Divide the list into two halves
    second_half=slow_ptr;
    prev_of_slow_ptr->next=NULL;
    reverse(&second_half);
    result=compareLists(head,second_half);

    reverse(&second_half);
    if(middle_node!=NULL)
    {
        prev_of_slow_ptr->next=middle_node;
        middle_node->next=second_half;
    }
    else
        prev_of_slow_ptr->next=second_half;
    return result;
}

void reverse(struct node** head)
{
    struct node* prev=NULL;
    struct node* current=*head;
    struct node* next;

    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;
}

int compareLists(struct node* head1,struct node* head2)
{
    struct node* temp1=head1;
    struct node* temp2=head2;

    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data==temp2->data)
        {
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else
        return 0;
    }

    if(temp1==NULL && temp2==NULL)
        return 1;

    return 0;

}

void insert(struct node** head,int data)
{
     struct node* nd=newNode(data);
     struct node* temp=*head;
     *head=nd;
     nd->next=temp;
}

void printList(struct node* head)
{
    struct node* node_ptr=head;
    while(node_ptr!=NULL)
    {
        printf("%d\t",node_ptr->data);
        node_ptr=node_ptr->next;
    }
    printf("\n");
}

int main()
{
    struct node* head=NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,2);
    insert(&head,1);
    printList(head);
    isPalindrome(head)?printf("IS PALINDROME\n"):printf("NOT A PALINDROME\n");
    return 0;
}
