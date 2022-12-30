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
int sum(string s){
    int sum=0;
    for(int i=0;i<s.size();i++){
        sum+=int(s[i]);
    }
    return sum;
}
int main(){
    int c=0;
    powerSetString("201",0,"");
    for(auto i:arr){
        if(sum(i)!=3)
        c+=1;
    }
cout<<c;
     return 0;
}