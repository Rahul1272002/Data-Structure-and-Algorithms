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
void postoder(struct Node* root )
{
    if(root==NULL)
      return;
        postoder(root->left);
        postoder(root->right);
        printf(" %d",root->data);
    
}
int main()
{  
   struct Node* p=createNode(4);
   struct Node* p1=createNode(1);
   struct Node* p2=createNode(6);
   struct Node* p3=createNode(5);
   struct Node* p4=createNode(2);
   /*
               4
              / \
            1    6   TREE
           / \
          5   2
          
    */

   p->left=p1;
   p->right=p2;
   p1->left=p3;
   p1->right=p4;
   postoder(p);
return 0;
}