#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
};
class tree{
public:
   node* createNode(int data){
    node *n; 
    n = new node(); 
    n->data = data;
    n->left = NULL; 
    n->right = NULL;
    return n; 
}
int hightOfATree(node*root)
{
   if(root==nullptr)
      return 0;
    return max(hightOfATree(root->left),hightOfATree(root->right))+1;
}
void Inoder(node* root )
{
    if(root!=NULL)
    {
        Inoder(root->left);
        cout<<" "<<root->data;
        Inoder(root->right);
    }
}
void insert(node* root,int key)
{  node* prev=NULL;

    while (root!=NULL)
    {   prev=root;
       if(key<root->data) 
          root=root->left;
        else
          root=root->right;
    }
   node* new1=createNode(key);
   if(key<prev->data)
    prev->left=new1;
    else
    prev->right=new1;
  
}
};


int main(){
     int n; 
    // Constructing the root node - Using Function (Recommended)
   tree x;
    node *p =  x.createNode(25);
    node *p1 = x.createNode(16);
    node *p2 = x.createNode(30);
    node *p3 = x.createNode(15);
    node *p4 = x.createNode(19);
    node *p5 =  x.createNode(22);
    node *p6 = x.createNode(31);
    node *p7 = x.createNode(18);
    node *p8 = x.createNode(21);
    node *p9 = x.createNode(20);
    // Finally The tree looks like this:
    //                           25
    //                          / \
    //                       16    30
    //                      / \    / \
    //                    15  19  22 31
    //                       / \
    //                     18  21
    //                         /
    //                        20

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;
    p4->left = p7;
    p4->right = p8;
    p8->left=p9;



x.Inoder(p);
cout<<"\nhight of tree:"<<x.hightOfATree(p)-1;
    return 0;
}