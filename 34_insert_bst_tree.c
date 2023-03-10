#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
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
            printf("\nElement %d already in this tree\n",root->data);
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

int main(){
     int n; 
    // Constructing the root node - Using Function (Recommended)
    struct node *p =  createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Finally The tree looks like this:
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

printf("Before insert element,inoder travers tree elements:\n");
Inoder(p);
printf("\nEnter element for insert Bst tree:");
scanf("%d",&n);    
insert(p,n);
insert(p,99);
printf("After insert element,inoder travers tree elements:\n");
Inoder(p);

    return 0;
}