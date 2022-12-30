#include<iostream>
#include<vector>
using namespace std;

int storeRainWater(vector<int>&arr){
    vector<int>left(arr.size()),right(arr.size());
   
    left[0]=arr[0];
    right[arr.size()-1]=arr[arr.size()-1];
    for(int i=1;i<arr.size();i++){
        left[i]=max(left[i-1],arr[i]);
    }
    for(int i=arr.size()-2;i>=0;i--){
        right[i]=max(right[i+1],arr[i]);
    }
int res=0;
for(int i=0;i<arr.size();i++){
    res+=(min(left[i],right[i])-arr[i]);
}
return res;

}
int main(){
     vector<int>arr={3,1,2,4,0,1,3,2};
     cout<<storeRainWater(arr);


     return 0;
}