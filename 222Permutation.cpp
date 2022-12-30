#include<iostream>
#include<vector>
using namespace std;
class Permutation {
private:  
void solve(vector<string>nums,vector<vector<string>>&ans,int index){
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
public:
    vector<vector<string>> permute(vector<string>& nums) {
        vector<vector<string>> ans;
        int sindex=0;
        solve(nums,ans,sindex);
        return ans;
    }
};

int main(){
    vector<string>arr={"a","b","c"};
    Permutation p;
    vector<vector<string>>res;
    res=p.permute(arr);
 for(auto i:res){
    cout<<"[";
    int ind=0;
    int last=i.size()-1;
    for(auto j:i){
        if(ind!=last)
        cout<<j<<" ";
        else
        cout<<j;
        ind+=1;
    }
    cout<<"] ";
 }

return 0;
}