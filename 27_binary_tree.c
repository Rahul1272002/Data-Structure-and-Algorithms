#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node*left;
    struct Node*right;
};
struct Node* createNode(int data)
{
    struct Node *n;//creating the node pointer 
   n=(struct Node*)malloc(sizeof(struct Node));
   n->data=data;//setting data
   n->left=NULL;//setting left and right child
   n->right=NULL;
   return n;
}
int main()
{  
    /*
     //this the root node
   struct Node *p;
   p=(struct Node*)malloc(sizeof(struct Node));
   p->data=33;
   p->left=NULL;
   p->right=NULL;
  //second node
   struct Node *p1;
   p1=(struct Node*)malloc(sizeof(struct Node));
   p1->data=23;
   p1->left=NULL;
   p1->right=NULL;
//third Node
   struct Node *p2;
   p2=(struct Node*)malloc(sizeof(struct Node));
   p2->data=3;
   p2->left=NULL;
   p2->right=NULL;
//linked root node with left and right children
   p->left=p1;
   p->right=p2;

   */ 
  
   struct Node* p=createNode(33);
   struct Node* p1=createNode(23);
   struct Node* p2=createNode(3);
   

   p->left=p1;
   p->right=p2;
return 0;
}