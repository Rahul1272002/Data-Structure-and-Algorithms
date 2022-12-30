#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node* left;
    struct node* right;
    int height;
};

int getHeight(struct node* n)
{
    if(n==NULL)
        return 0;
 
     return n->height;
}
struct node* CreateNode(int key)
{
   struct node* node=(struct node*)malloc(sizeof(struct node));
   node->key=key;
   node->left=NULL;
    node->right=NULL;
   node->height=1;
return node;
}
int max(int a,int b)
{
   return (a>b)?a:b;
}
int getbalanceFactor(struct node*n)
{
    if(n==NULL)
    return 0;
    return getHeight(n->left)-getHeight(n->right);
}
struct node* rightRotate(struct node* y)
{  struct node* x= y->left;
   struct node* T2=x->right;
    
    x->right=y;
    y->left=T2;

x->height=max(getHeight(x->right),getHeight(x->left))+1;
y->height=max(getHeight(y->right),getHeight(y->left))+1;

return x;
    
}
struct node* leftRotate(struct node*x)
{
    struct node* y= x->right;
   struct node* T2=y->left;
    
    y->left=x;
    x->right=T2;


x->height=max(getHeight(x->right),getHeight(x->left))+1;
y->height=max(getHeight(y->right),getHeight(y->left))+1;
return y;
}
struct node* insert(struct node* node,int key)
{    
    if(node==NULL)
     return CreateNode(key);

    if(key<node->key)
       node->left=insert(node->left,key);
    
    else if(key>node->key)
       node->right=insert(node->right,key);
       
node->height=1+max(getHeight(node->left),getHeight(node->right)); //This is for leaf node 1st time (update hight)
    int bf=getbalanceFactor(node);

//For LL case 
if(bf>1 && key< node->left->key)
  return  rightRotate(node);
//For RR case
if(bf<-1 && key> node->right->key)
  return  leftRotate(node);
//For LR case
if(bf>1 && key>node->left->key)
{  node->left=leftRotate(node->left);
    return  rightRotate(node);
}
  
//For RL case  
if(bf<-1 && key< node->right->key)
{   node->right=rightRotate(node->right);
    return leftRotate(node);
}

return node;
   
         
}
void preorder(struct node* root )
{
    if(root!=NULL)
    {
        printf(" %d",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
void Inorder(struct node* root )
{
    if(root!=NULL)
    {
        Inorder(root->left);
        printf(" %d",root->key);
        Inorder(root->right);
    }
}
void postorder(struct node* root )
{
    if(root==NULL)
      return;
        postorder(root->left);
        postorder(root->right);
        printf(" %d",root->key);
}
int main()
{ 
    struct node*root=NULL;
        root=insert(root,1);
        root=insert(root,2);
        root=insert(root,4);
        root=insert(root,5);
        root=insert(root,6);
        root=insert(root,3);
        printf("Preorder:");
    preorder(root);
     printf("\nIorder:");
    Inorder(root);
     printf("\nPostorder:");
    postorder(root);
   // printf("h:%d",root->height);
    return 0;
}