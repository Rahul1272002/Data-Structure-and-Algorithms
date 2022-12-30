#include<stdio.h>
#include<stdlib.h>

struct Node
{  
      int data;
      struct Node* next;
      struct Node* prev;
};
void AddData(struct Node* head,int data)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node*p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    ptr->data=data;
    p->next=ptr;
    ptr->prev=p;
    ptr->next=NULL;

}
void linklistTraversal(struct Node* head)
{   
    struct Node* ptr=head;
    printf("Left to Right >>>>\n");
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
       if(ptr->next==NULL)
        {   printf("%d->NULL",ptr->data);
             break; 
        }
    }
    printf("\n\nRight to left<<<<<<\n");
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->prev;
    }
    printf("NULL");
}

int main()
{  struct Node* HEAD;
    HEAD=(struct Node*)malloc(sizeof(struct Node));
    int node,d,k=2,n;
printf("Enter node limit:");
scanf("%d",&node);
printf("Enter node 1:");
scanf("%d",&n);
HEAD->data=n;
HEAD->next=NULL;
HEAD->prev=NULL;
while(k<=node)
{
    printf("\nEnter node %d:",k);
    scanf("%d",&d);
    AddData(HEAD,d);
    k++;
}
    
    linklistTraversal(HEAD);
  
   


  return 0;  
}