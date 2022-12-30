#include<stdio.h>

#include<stdlib.h>

struct Node
{  
      int data;
      struct Node* next;

};
void linklistTraversal(struct Node* ptr)
{
    while(ptr!=NULL)
    {
        printf("Element=%d\n",ptr->data);
        ptr=ptr->next;
    }
}
struct Node* InsertEnd(struct Node* head,int data)
{
    struct Node* ptr=(struct Node*) malloc(sizeof(struct Node));
    struct Node* p=head;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    ptr->data=data;
    ptr->next=NULL;
    p->next=ptr;
    return head;
    
}
int main()
{
    struct Node* head;
    struct Node* second;
    struct Node* third;

    head=(struct Node*) malloc(sizeof(struct Node));
    second=(struct Node*) malloc(sizeof(struct Node));
    third=(struct Node*) malloc(sizeof(struct Node));

    head->data=7;
    head->next=second;

    second->data=99;
    second->next=third;

    third->data=30;
    third->next=NULL;
    printf("Before:\n");
    linklistTraversal(head);
    printf("\n\nAfter:\n");
    head=InsertEnd(head,900);
   linklistTraversal(head);


  return 0;  
}