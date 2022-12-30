#include<stdio.h>
#include<stdlib.h>
struct Node
{
   int data ;
   struct Node* next;
};
struct Node* top=NULL;
void linklistTraversal(struct Node* ptr)
{
   while(ptr!=NULL)
   {
      printf("Element:%d\n",ptr->data);
      ptr=ptr->next;
   }
}

int is_full(struct Node* top)
{   struct Node* n=(struct Node*) malloc(sizeof(struct Node));
   if(n==NULL)
   return 1;
   else
   return 0;
}
int is_empty(struct Node* top)
{
   if(top==NULL)
       return 1;
       else
       return 0;
}
struct Node* push(struct Node* top,int x)
{
   if(is_full(top))
     printf("Stack overflow");
     else
     {  
      struct Node* n=(struct Node*) malloc(sizeof(struct Node));
        
        n->data=x;
        n->next=top;
        top=n;
        return top;

     }
}
  
int pop(struct Node* tp)
{
   if(is_empty(tp))
     printf("Stack underflow");
     else
     {  
      struct Node* n=tp;
       top=tp->next;
       int x=n->data;
       free(n);
       return x;


     } 
}
int peek(int pos)
{
    struct Node*ptr=top;
    int i;
    for(i=0;(i<pos-1 && ptr!=NULL);i++)
    {
        ptr=ptr->next;
    }
    if(ptr!=NULL)
       return ptr->data;
    else
    return -1;
    
}
int main()
{
   int i;
   top=push(top,28);
   top=push(top,18);
   top=push(top,15);
   top=push(top,7);

   linklistTraversal(top);
   for(i=1;i<=4;i++)
   {
       printf("\nvalue at postion %d is:%d",i,peek(i));
   }

  return 0;
}