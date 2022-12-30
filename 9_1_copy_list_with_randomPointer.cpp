#include<iostream>
#include<unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
    void insertAtTail(Node* &head,Node* &tail,int data){
       Node*newnode=new Node(data);
        if(head==nullptr)
        {
            head=newnode;
            tail=newnode; 
            return;
        }
        else{
            tail->next=newnode;
            tail=newnode;
             
        }
    }
public:
    Node* copyRandomList(Node* head) {
        Node*cloneHead=nullptr;
        Node*cloneTail=nullptr;
        Node*p=head;
        while(p!=nullptr){
            insertAtTail(cloneHead,cloneTail,p->val);
           p=p->next;
        }
        
        unordered_map<Node*,Node*>oldTonew;
        Node*originalNode=head;
        Node*cloneNode=cloneHead;
        while(originalNode!=nullptr){
            oldTonew[originalNode]=cloneNode;
            originalNode=originalNode->next;
            cloneNode=cloneNode->next; 
        }
        originalNode=head;
        cloneNode=cloneHead;
        
      while(originalNode!=nullptr){
            cloneNode->random=oldTonew[originalNode->random];
             originalNode=originalNode->next;
            cloneNode=cloneNode->next; 
        }  
        return cloneHead;
    }
};
int main(){
    return 0;
}