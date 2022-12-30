#include<stdio.h>
#include<stdlib.h>
struct Node*r=NULL;
    struct Node*f=NULL;
struct Node
{  
      int data;
      struct Node* next;

};
void linklistTraversal(struct Node* ptr)
{
    while(ptr!=NULL)
    {
        printf("\nElement=%d",ptr->data);
        ptr=ptr->next;
    }
}
void enqueue(int val)
{
    struct Node*n=(struct Node*)malloc(sizeof(struct Node));
    if(n==NULL)//check when full
    printf("\nQueue is Full");
    else
    { n->data=val;
      n->next=NULL;
       if(f==NULL)
       { 
           f=r=n;
         
       }
       else
       {
         r->next=n;
         r=n;
       }
    }
}
int dequeue()
{
    int val=-1;
    struct Node*ptr=f;
    if(f==NULL)
    printf("\nQueue is empty");
    else
    { 
        f=f->next;
      val=ptr->data;
      free(ptr);
    }
    return val;
}
int main()
{   //printf("\nDequeue element %d",dequeue());
   enqueue(89);
   enqueue(9);
   enqueue(439);
   enqueue(893);
   linklistTraversal(f);
   printf("\nDequeue element %d",dequeue());
   linklistTraversal(f);

    return 0;
}