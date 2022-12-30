#include<stdio.h>
#include<stdlib.h>
struct Node
{
   int data ;
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
int main()
{
   struct Node* top=NULL;
   top=push(top,45);
   top=push(top,47);
   top=push(top,43);
   top=push(top,95);
    linklistTraversal(top);
return 0;
}