#include<iostream>
#include<unordered_map>
using namespace std;
void countDistinct(int*arr,int k,int size){
    unordered_map<int,int>hs;
int count=0;
 for(int i=0;i<k;i++)
 {  if(hs[arr[i]]==0)
      count+=1;

      hs[arr[i]]+=1;
 }

cout<<count<<endl;

for(int i=k;i<size;i++)
{
    if (hs[arr[i - k]] == 1) {
           count--;
        } 
        hs[arr[i - k]] -= 1;
         if (hs[arr[i]] == 0) {
           count++;
        }
        hs[arr[i]] += 1;

        cout<<count<<endl;

}
}

int main()
{
    int arr[]={1,2,1,3,4,2,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k=4;
    countDistinct(arr,k,size);
return 0;
}
