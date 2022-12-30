#include<stdio.h>
#include<stdlib.h>

struct Node
{
   int data;
   struct Node* next;
};
 void linklistTraversal(struct Node* head)
{   struct Node* ptr=head;
 
    do 
    {  
    printf("Element: %d\n",ptr->data);
    ptr=ptr->next;
    }while(ptr!=head);
    
}
struct Node* insrtAtfirst(struct Node* head,int data)
{
    struct Node* ptr=(struct Node*) malloc(sizeof(struct Node));
     ptr->data=data;
    struct Node* p=head->next;

    while (p->next!=head)
    {
        p=p->next;
    }
  
    p->next=ptr;
    ptr->next=head;
    head=ptr;
   
    return head;
}

int main()
{
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    struct Node* fiveth;

    head=(struct Node*) malloc(sizeof(struct Node));
    second=(struct Node*) malloc(sizeof(struct Node));
    third=(struct Node*) malloc(sizeof(struct Node));
    fourth=(struct Node*) malloc(sizeof(struct Node));
    fiveth=(struct Node*) malloc(sizeof(struct Node));

    head->data=7;
    head->next=second;

    second->data=11;
    second->next=third;

    third->data=66;
    third->next=fourth;

    fourth->data=99;
    fourth->next=fiveth;

   fiveth->data=103;
   fiveth->next=head;
   printf("Before:\n");
   linklistTraversal(head);      
   head=insrtAtfirst(head,54);
      
   printf("\n\nAfter:\n");
  linklistTraversal(head);      
    return 0;
}