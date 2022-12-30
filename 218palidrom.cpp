#include<iostream>
#include<string>
using namespace std;
bool palindrom(string s,int f,int l)
{
  if(f>=l)
    return true;

 if(s.at(f)!=s.at(l))
  { 
      return false;
  }

return palindrom(s,f+1,l-1);
  
}
int main()
{
string s;
cin>>s;
if(!palindrom(s,0,s.length()-1))
cout<<"Not Palindrom";
else    
cout<<"Palindrom";

return 0;

}