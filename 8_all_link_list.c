#include<stdio.h>
#include<stdlib.h>
//#include<process.h>

struct Node
{  
      int data;
      struct Node* next;
};
struct Node* AddData(struct Node* head,int data)
{    if(head==NULL)
      {
          head=(struct Node*)malloc(sizeof(struct Node));
          head->data=data;
          head->next=NULL;
          return head;
      }
    else{
         struct Node*p=head;
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    while(p->next!=NULL)
        p=p->next;

    ptr->data=data;
    p->next=ptr;
    ptr->next=NULL;
    return head;
    }
   

}
void linklistTraversal(struct Node* ptr)
{   if(ptr==NULL)
        printf("\nEmpty Node\n");
        else
        {
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
        }
}
struct Node* insrtAtfirst(struct Node* head,int data)
{
    struct Node* ptr=(struct Node*) malloc(sizeof(struct Node));
    
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
struct Node* InsertBefore(struct Node* head,int data,int index)
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
struct Node* InsertAfter(struct Node* head,int data,int index)
{
    struct Node* ptr=(struct Node*) malloc(sizeof(struct Node));
    struct Node* p=head;
    int i=0;
    while (i!=index)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
    
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
struct Node* deleteFirst(struct Node* head)
{
    struct Node* ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
struct Node* deleteValue(struct Node* head,int data)
{   
    struct Node* p=head;
    struct Node* q=head->next;
    while(q->data!=data && q->next!=NULL)
     {
         p=p->next;
         q=q->next;
     }
    if(q->data==data)
    {
         p->next=q->next;
         free(q);
    }
  

    return head;
}
struct Node* deleteEnd(struct Node* head)
{   int i;
    struct Node* q=head,*p=head->next;

    while (p->next!=NULL)
    {    q=q->next;
         p=p->next;
    }  
    free(p);
     q->next=NULL;   
    
    return head;
}
int main()
{  struct Node* HEAD=NULL;
    
    int node,d,k=1,n;
printf("Enter node limit:");
scanf("%d",&node);
while(k<=node)
{
    printf("\nEnter node %d:",k);
    scanf("%d",&d);
    HEAD=AddData(HEAD,d);
    k++;
}
    printf("Before:");
    linklistTraversal(HEAD);
    
    int i,val,num;
    while(1)
    {
         printf("\n\nEnter 1 for Insert a new node at the beginning\nEnter 2 for Insert a new node at the end\nEnter 3 for Insert a new node after a given node with a specific value\nEnter 4 for Insert a new node before a given node with a specific value.t\nEnter 5 for Delete a node at the beginning.\nEnter 6 for Delete a node at the end.\nEnter 7 for Delete a node with a specific value\nEnter 0 for exit\n");
   printf("Enter your choice\n");
    scanf("%d",&num);
    switch (num)
    {
    case 0:
      exit(0);
    case 1:
    printf("Enter insert value: ");
    scanf("%d",&val);
          printf("\nAfter Insert:\n");
        HEAD=insrtAtfirst(HEAD,val);
    linklistTraversal(HEAD);
        break;
    case 2:
    printf("Enter insert value: ");
    scanf("%d",&val);
          printf("\nAfter Insert:\n");
    HEAD=InsertEnd(HEAD,val);
   linklistTraversal(HEAD);
    break; 
    case 3:
    printf("Enter insert index: ");
    scanf("%d",&i);
    printf("Enter insert value: ");
    scanf("%d",&val);    
    HEAD=InsertAfter(HEAD,val,i);
    linklistTraversal(HEAD);
    break;
    case 4:
       printf("Enter insert index: ");
    scanf("%d",&i);
    printf("Enter insert value: ");
    scanf("%d",&val);
        
    HEAD=InsertBefore(HEAD,val,i);
    linklistTraversal(HEAD);
    break;
    
   
    case 5:
     printf("\nAfter:\n");
    HEAD= deleteFirst(HEAD);
   linklistTraversal(HEAD);
   break;
    case 6:
     HEAD=deleteEnd(HEAD);
     linklistTraversal(HEAD);
     break;
    default:
    printf("\nInvalid Input\n");
        break; 
    
   case 7:
   printf("Enter delete value: ");
    scanf("%d",&val);
     printf("\nAfter:\n");
   HEAD=deleteValue(HEAD,val);
   linklistTraversal(HEAD);
   break;
  
    }
   
    }
   
   


  return 0;  
}