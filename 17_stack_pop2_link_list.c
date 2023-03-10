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
int main()
{
   
   top=push(top,45);
   top=push(top,47);
   top=push(top,43);
   top=push(top,95);

   linklistTraversal(top);

   int element=pop(top);
   printf("\npoped elemnet:%d\n",element);

    linklistTraversal(top);
return 0;
}