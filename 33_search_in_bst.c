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
struct node* SEARCH(struct node* root,int key)
{
    while (root!=NULL)
    {
        if(key==root->data)
          return root;
        else if(key<root->data) 
          root=root->left;
        else
         root=root->right;
    }
    
    return NULL;
    
}

int main(){
     
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
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
//struct node* n=SEARCH(p,9);
struct node* n=SEARCH(p,4);
if(n!=NULL)
   printf("Element found %d",n->data);
   else
    printf("Element not found");
    return 0;
}
