#include<iostream>
#include<vector>
using namespace std;

void solve(string nums,vector<string>&ans,int index){
    //base case
    if(index>=nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for(int j=index;j<nums.size();j++){
        swap(nums[index],nums[j]);
        solve(nums,ans,index+1);
        //Backtrack
        swap(nums[index],nums[j]);
    }
}
vector<string> generatePermutations(string &str)
{
    // write your code here
    vector<string>ans;
        int sindex=0;
        solve(str,ans,sindex);
        return ans;
}
int main(){
    vector<string>arr;
    string a="bc";
    arr=generatePermutations(a);
    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}