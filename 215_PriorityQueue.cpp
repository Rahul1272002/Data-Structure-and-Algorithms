#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int>q;
    q.push(3);
    q.push(100);
    q.push(33);
     q.push(30);
    q.push(0);
    q.push(11);
    while (!q.empty())
    {
        cout<<q.top()<<endl;
        q.pop();
    }
    
    return 0;
}