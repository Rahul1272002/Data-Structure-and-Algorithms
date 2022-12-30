#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
#include<unordered_map>
#include<list>
using namespace std;
vector<pair<pair<int,int>,int>>prims(int n,int m,vector<pair<pair<int,int>,int>>&g){
           unordered_map<int,list<pair<int,int>>>adj;
    vector<pair<pair<int,int>,int>>res;
   for(int i=0;i<g.size();i++)
   {
        int u=g[i].first.first;
        int v=g[i].first.second;
        int w=g[i].second;
        adj[u].push_back(make_pair(v,w));
         adj[v].push_back(make_pair(u,w));

   }
   vector<int>key(n+1);
   vector<bool>visited(n+1);
   vector<int>parent(n+1);

   for(int i=0;i<=n;i++){
     key[i]=INT_MAX;
     parent[i]=-1;
     visited[i]=false;
   }

key[0]=0;
parent[0]=-1;

for(int i=0;i<n;i++)
{
    int min=INT_MIN; 
    int u;

    //find min node
    for(int v=0;v<=n;v++){
        if(visited[v]==false && key[v]<min){
            u=v;
            min=key[v];  
        }
    }

    //Mark min node as true
    visited[u]=true;


    //check adj nodes
    for(auto it:adj[u])
    {
        int v=it.first;
        int w=it.second;
        if(visited[v]==false && w<key[v])
         {
            parent[v]=u;
            key[v]=w;
         }
    }
}


for(int i=1;i<=n;i++)
{
    res.push_back({{parent[i],i},key[i]});

}
return res;
}


int main()
{
    int n=5,m=15;
vector<pair<pair<int,int>,int>>l;
l.push_back({{0,1},2});
l.push_back({{0,4},6});
l.push_back({{1,0},2});
l.push_back({{1,2},1});

l.push_back({{1,4},4});
l.push_back({{2,1},1});
l.push_back({{2,3},3});
l.push_back({{2,4},2});
l.push_back({{3,2},3});
l.push_back({{3,4},5});
l.push_back({{3,0},7});
l.push_back({{4,0},6});
l.push_back({{4,1},4});
l.push_back({{4,3},5});






/*={{{0,1},2},
                                  {{0,4},6},
                                  {{1,0},2},
                                  {{1,2},1},
                                  {{1,4},4},
                                  {{2,1},1},
                                  {{2,3},3},
                                  {{2,4},2},
                                  {{3,2},3},
                                  {{3,4},5},
                                  {{3,0},7},
                                  {{4,0},6},
                                  {{4,1},4},
                                  {{4,2},2},
                                  {{4,3},5}};
                                  */
        vector<pair<pair<int,int>,int>>res=prims(n,m,l);

    return 0;
}