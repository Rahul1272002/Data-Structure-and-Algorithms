#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createNode(int data)
{
    struct node *n; 
    n = (struct node *) malloc(sizeof(struct node)); 
    n->data = data;
    n->left = NULL; 
    n->right = NULL;
    return n; 
}
void Inoder(struct node* root )
{
    if(root!=NULL)
    {
        Inoder(root->left);
        printf(" %d",root->data);
        Inoder(root->right);
    }
}
void insert(struct node* root,int key)
{  struct node* prev=NULL;

    while (root!=NULL)
    {   prev=root;
        if(key==root->data)
        {
            printf("\nElement %d already in this tree",root->data);
            return;
        }
        else if(key<root->data) 
          root=root->left;
        else
          root=root->right;
    }
   struct node* new=createNode(key);
   if(key<prev->data)
     prev->left=new;
   else
     prev->right=new;
  
}
struct node* inoderpredecessor(struct node* root)
{   
    root=root->left;
while (root->right!=NULL)
{
  root=root->right;
}
return root;
}
struct node* deletnode(struct node* root,int val)
{ 
    struct node* ipr;
    if (root==NULL)
       return NULL;
    if(root->left==NULL && root->right==NULL)
     {
         free(root);
         return NULL;
     }
    if(val<root->data)
      root->left=deletnode(root->left,val);
    else if(val>root->data)
       root->right=deletnode(root->right,val);
    else
    {   
        ipr=inoderpredecessor(root);
        root->data=ipr->data;
        root->left=deletnode(root->left,ipr->data);
       
    } 
    
    return root;
}
int main(){

    struct node *p =  createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4); 
    // tree looks like
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
Inoder(p);
deletnode(p,3);
printf("\n");
Inoder(p);

  return 0;
}