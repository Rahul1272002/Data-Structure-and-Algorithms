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
struct Node* InsertBetween(struct Node* head,int data,int index)
{
    struct Node* ptr=(struct Node*) malloc(sizeof(struct Node));
    struct Node* p=head;
    int i=0;
    while (i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
    
}
struct Node* deleteIndex(struct Node* head,int index)
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

    second->data=71;
    second->next=third;

    third->data=66;
    third->next=fourth;

    fourth->data=99;
    fourth->next=fiveth;

   fiveth->data=103;
   fiveth->next=NULL;

    printf("Before:\n");
    linklistTraversal(head);
    int i,val,num;
    printf("Enter 1 for insert between\nEnter 2 for deletion:\n");
    scanf("%d",&num);

    
   
    switch (num)
    {
    case 1:
    printf("Enter insert index: ");
    scanf("%d",&i);
    printf("Enter insert value: ");
    scanf("%d",&val);
          printf("\n\nAfter:\n");
    head=InsertBetween(head,val,i);
    linklistTraversal(head);
        break;
    case 2:
    printf("Enter delete index: ");
    scanf("%d",&i);
    printf("\n\nAfter:\n");
    head=deleteIndex(head,i);
    linklistTraversal(head);
    break;
    
    default:
    printf("Invalid ");
        break;
    }
   
   


  return 0;  
}