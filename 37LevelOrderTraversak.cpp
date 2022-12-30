#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
    
};

void Inorder(Node*root)
    {
        if (root==nullptr)
         return;
         Inorder(root->left);
         cout<<root->data<<" ";
         Inorder(root->right);
    }
 void printLevelOrder(Node*root,int level)
 {
     if(root==nullptr)
         return;
    if (level==1)
         cout<<root->data<<" ";
    else if(level>1)
    {
        printLevelOrder(root->left,level-1);
        printLevelOrder(root->right,level-1);
    }
 }  
 int maxDepth(Node*root)
 {
     if(root==nullptr)
         return 0;
    // int ldepth=maxDepth(root->left);
    //    int rdepth=maxDepth(root->right);
    
    // if (ldepth>rdepth)
    //     return(ldepth+1);
    // else
    //    return (rdepth+1);

    return max(maxDepth(root->left),maxDepth(root->right))+1;
 } 
int main(){
Node*root=new Node(4);
root->left=new Node(5);
root->right=new Node(1);

root->left->left=new Node(7);
root->left->right=new Node(9);

Inorder(root);
cout<<endl;
int n=maxDepth(root);
cout<<"Height of this tree is:"<<n<<endl;
for(int i=1;i<=n;i++){
printLevelOrder(root,i);
cout<<endl;
}

return 0;
}
