#include <iostream>
#include<stack>
using namespace std; 
void  solve(stack<int>& myStack, int x){
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    int top=myStack.top();
    myStack.pop();
    solve(myStack,x);
    myStack.push(top);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    solve(myStack,x);
    return myStack;
    
}
void print(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
int main(){
stack<int>ele;
       ele.push(1);
       ele.push(2);
       ele.push(3);
       ele.push(4);
       ele.push(5);
       print(ele);
    pushAtBottom(ele,9);
    print(ele);

return 0;
}