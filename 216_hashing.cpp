#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{unordered_set<int>s;

s.insert(5);
s.insert(112);
s.insert(100);
if(s.find(5)==s.end())
   cout<<"Not found";
else
   cout<<"found";

unordered_set<int>::iterator ptr;
s.erase(112);
s.erase(s.begin(),s.end());

for(ptr=s.begin();ptr!=s.end();ptr++)
{
   cout<<"\n"<<*ptr;
}

s.clear();
cout<<"\n"<<s.size();
    return 0;
}