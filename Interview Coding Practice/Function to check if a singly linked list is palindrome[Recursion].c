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

bool isPalindromeUtil(struct node** left,struct node* right)
{
    if(right==NULL)
        return true;

    bool isp=isPalindromeUtil(left,right->next);
    if(isp==false)
        return false;

    bool isp1=(right->data==(*left)->data);
    *left=(*left)->next;
    return isp1;
}

bool isPalindrome(struct node* head)
{
    isPalindromeUtil(&head,head);
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
