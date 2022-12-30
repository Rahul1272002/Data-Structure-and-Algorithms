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
struct Node* insrtAtfirst(struct Node* head,int data)
{
    struct Node* ptr=(struct Node*) malloc(sizeof(struct Node));
    
    ptr->next=head;
    ptr->data=data;
    return ptr;
}

int main()
{
    struct Node* head;
    struct Node* second;
    struct Node* third;
    //alocated memory for nodes in the list in heap
    head=(struct Node*) malloc(sizeof(struct Node));
    second=(struct Node*) malloc(sizeof(struct Node));
    third=(struct Node*) malloc(sizeof(struct Node));
    //Link node
    head->data=7;
    head->next=second;


    second->data=11;
    second->next=third;

    third->data=66;
    third->next=NULL;
    
    linklistTraversal(head);
    printf("\n\n");
    head=insrtAtfirst(head,90);
    linklistTraversal(head);

    return 0;

}