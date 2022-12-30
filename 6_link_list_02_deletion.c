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
    printf("Element:%d\n",ptr->data);
    ptr=ptr->next;
    }
    
}
struct Node* deletIndex(struct Node* head,int index)
{   int i;
    struct Node* p=head;
    struct Node* q=head->next;
   for(i=0;i<index-1;i++)
   {
       p=p->next;
       q=q->next;

   }
   p->next=q->next;
   free(q);

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
   fiveth->next=NULL;
   printf("Before:\n");
   linklistTraversal(head);
   printf("\n\nAfter:\n");
    head=deletIndex(head,2);
   linklistTraversal(head);

    return 0;
}