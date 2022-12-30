#include<iostream>
#include<stack>
using namespace std;
class Solution
{ private:
        void solve(stack<int>&s, int size,int count){
            if(count==size/2){
                s.pop();
                return;
            } 
            int top=s.top();
            s.pop();
            solve(s,size,count+1);
            s.push(top);
        }
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here..
        int count=0;
       solve(s,sizeOfStack,count);
    }
};
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
     Solution res;
     res.deleteMid(ele,ele.size());
     print(ele);
    return 0;
}