#include<stdio.h>
#include<stdlib.h>

struct Node
{
   int data;
   struct Node* prev;
   struct Node* next;
}; 
 void linklistTraversal(struct Node* head)
{   
    struct Node* ptr=head;
    /*do  
    {  
    printf("Element: %d\n",ptr->data);
    ptr=ptr->next;
    }while(ptr!=head//NULL);*/
    printf("Left to Right >>>>\n");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
        if(ptr->next==NULL)
        {   printf("%d",ptr->data);
             break; 
        }
        
        
    }
    printf("\nRight to left<<<<<<\n");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->prev;
    }

    
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
    head->prev=NULL;

    second->data=11;
    second->next=third;
    second->prev=head;

    third->data=66;
    third->next=fourth;
    third->prev=second;

    fourth->data=99;
    fourth->next=fiveth;
    fourth->prev=third;

   fiveth->data=103;
   fiveth->next=NULL;
   fiveth->prev=fourth;

   
   linklistTraversal(head);      
  
    return 0;
}