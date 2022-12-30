#include <iostream>
#include <stack>
using namespace std;
class Solution
{
private:
    void pushAtButtom(stack<int> &s, int x)
    {
        if (s.empty())
        {
            s.push(x);
            return;
        }
        int top = s.top();
        s.pop();
        pushAtButtom(s, x);
        s.push(top);
    }
    void rev(stack<int> &s)
    {
        if (s.empty())
        {
            return;
        }
        int top = s.top();
        s.pop();
        rev(s);
        pushAtButtom(s, top);
    }

public:
    stack<int> Reverse(stack<int> &St)
    {
        rev(St);
        return St;
    }
};
void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main()
{
    stack<int> ele;
    ele.push(1);
    ele.push(2);
    ele.push(3);
    ele.push(4);
    ele.push(5);
    print(ele);
    Solution res;
    res.Reverse(ele);
    print(ele);

    return 0;
}