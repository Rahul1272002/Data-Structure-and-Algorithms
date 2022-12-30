#include<iostream>
#include<vector>
using namespace std;
vector<string>arr;
void powerSetString(string s,int index,string cur){
    if(index==s.size())
     {
        arr.push_back(cur);
        return;
     }
     powerSetString(s,index+1,cur+s[index]);
     powerSetString(s,index+1,cur);
}

int main(){
    powerSetString("abc",0,"");
    for(auto i:arr){
        cout<<i<<" ";
    }

     return 0;
}